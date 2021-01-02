#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct adjacency_list_node
{
    int destination;
    int weight;
    struct adjacency_list_node *next;
} a_list_node;
typedef struct adjacency_node
{
    struct adjacecy_list_node *head;
} a_list;

typedef struct graph
{
    int vertices;
    a_list *list;
} graph;

struct a_list_node *new_a_list_node(int d, int w)
{
    a_list_node *new_node = (a_list_node *)malloc(sizeof(a_list_node));
    new_node->destination = d;
    new_node->weight = w;
    new_node->next = NULL;
    return new_node;
}
graph *create_graph(int vertex)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->vertices = vertex;
    g->list = (a_list *)malloc(vertex * sizeof(a_list));
    for (int j = 0; j < vertex; j++)
    {
        g->list[j].head = NULL;
    }

    return g;
}
void add_edge_to_graph(graph *g, int s, int d, int w)
{
    a_list_node *new_node = new_a_list_node(d, w);
    new_node->next = g->list[s].head;
    g->list[s].head = new_node;
    new_node = new_a_list_node(s, w);
    new_node->next = g->list[d].head;
    g->list[d].head = new_node;
}
typedef struct min_heap_node
{
    int v;
    int distance;
} m_h_n;
typedef struct min_heap
{
    int size;
    int capacity;
    int *position;
    m_h_n **list;
} m_h;
struct m_h_n *new_min_heap_node(int v, int distance)
{
    m_h_n *ptr = (m_h_n *)malloc(sizeof(m_h_n));
    ptr->v = v;
    ptr->distance = distance;
    return ptr;
}
struct m_h *create_min_heap(int capacity)
{
    m_h *ptr = (m_h *)malloc(sizeof(m_h));
    ptr->position = (int *)malloc(sizeof(int) * capacity);
    ptr->size = 0;
    ptr->capacity = capacity;
    ptr->list = (m_h_n **)malloc(sizeof(m_h_n *) * capacity);
    return ptr;
}
void swap_min_heap(m_h_n **x, m_h_n **y)
{
    m_h_n *temp = *x;
    *x = *y;
    *y = temp;
}
void min_heapify(m_h *min_heap, int index)
{
    int small, left, right;
    small = index;
    left = 2 * index + 1;
    right = 2 * index + 2;
    if (left < min_heap->size && min_heap->list[left]->distance < min_heap->list[small]->distance)
    {
        small = left;
    }
    if (right < min_heap->size && min_heap->list[right]->distance < min_heap->list[small]->distance)
    {
        small = right;
    }
    if (small != index)
    {
        m_h_n *ptr = min_heap->list[small];
        m_h_n *ptr1 = min_heap->list[index];
        min_heap->position[ptr->v] = index;
        min_heap->position[ptr1->v] = small;
        swap_min_heap(&min_heap->list[small], &min_heap->list[index]);
        min_heapify(min_heap, small);
    }
}
int empty_or_not(m_h *ptr)
{
    return ptr->size == 0;
}
m_h_n *extract(m_h *ptr)
{
    if (empty_or_not(ptr))
    {
        return NULL;
    }
    m_h_n *root = ptr->list[0];
    m_h_n *last_node = ptr->list[ptr->size - 1];
    ptr->list[0] = last_node;

    ptr->position[root->v] = ptr->size - 1;
    ptr->position[last_node->v] = 0;
    --ptr->size;
    min_heapify(ptr, 0);
    return root;
}

void decrease_key(m_h *ptr, int v, int distance)
{
    int i = ptr->position[v];
    ptr->list[i]->distance = distance;
    while (i && ptr->list[i]->distance < ptr->list[(i - 1) / 2]->distance)
    {
        ptr->position[ptr->list[i]->v] = (i - 1) / 2;
        ptr->position[ptr->list[(i - 1) / 2]->v] = i;
        swap_min_heap(&ptr->list[i], &ptr->list[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}
bool is_min_heap(m_h *ptr, int v)
{
    if (ptr->position[v] < ptr->size)
    {
        return true;
    }
    return false;
}

void list_print(int distance[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int k = 0; k < n; k++)
        printf("%d \t\t %d\n", k + 1, distance[k]);
}

void dijkstra_algo(graph *g, int s)
{

    int v = g->vertices;

    int dist[v];

    m_h *ptr = create_min_heap(v);

    for (int m = 0; m < v; m++)
    {
        dist[m] = INT_MAX;
        ptr->list[m] = new_min_heap_node(m, dist[m]);
        ptr->position[m] = m;
    }

    ptr->list[s] =
        new_min_heap_node(s, dist[s]);
    ptr->position[s] = s;
    dist[s] = 0;
    decrease_key(ptr, s, dist[s]);

    ptr->size = v;

    while (!empty_or_not(ptr))
    {

        m_h_n *p =
            extract(ptr);
        int u = p->v;

        a_list_node *ptr1 =
            g->list[u].head;
        while (ptr1 != NULL)
        {
            int v = ptr1->destination;

            if (is_min_heap(ptr, v) &&
                dist[u] != INT_MAX &&
                ptr1->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + ptr1->weight;
                decrease_key(ptr, v, dist[v]);
            }
            ptr1 = ptr1->next;
        }
    }

    list_print(dist, v);
}
int main()
{

    int v, e, s, d, w, x;
    printf("Welcome to Dijkstra Algorithm\n\n");
    printf("Enter the Number of Vertices\n");
    scanf("%d", &v);
    graph *g = create_graph(v);
    printf("Enter the number of the edges present in it\n");
    scanf("%d", &e);
    for (int i = 1; i <= e; i++)
    {
        printf("Enter the %d source vertex between 1 to %d \n", i, v);
        scanf("%d", &s);
        printf("Enter the %d Destination vertex between 1 to %d \n", i, v);
        scanf("%d", &d);
        printf("Enter the weight of the edge present between %d vertex and %d vertex \n", s, d);
        scanf("%d", &w);
        add_edge_to_graph(g, s - 1, d - 1, w);
    }

    printf("\nEdges are inserted Successfully\n");
    printf("Enter the Source vertex between 1 to %d from where you want to find the distance from each vertex\n", v);
    scanf("%d", &x);

    dijkstra_algo(g, x - 1);

    return 0;
}