#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 1000
int qu[size], top = -1, fro = -1, rea = -1, g[size][size], vis[size], stack[size];
struct queue *createQueue();
void enqueue(struct queue *q, int);
int dequeue(struct queue *q);
void display(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);
int delete ();
void add(int item);
void bfs(int s, int n);
void push(int item);
int pop();
// NOTE:
// ------
// Adjacency Matrix indexing start from 1 whereas Adjacency List indexing start from the 0
struct queue
{
    int items[size];
    int front;
    int rear;
};

struct node
{
    int vertex;
    struct node *next;
};

struct node *createNode(int);

struct Graph
{
    int num_vertices;
    struct node **adj_lists;
    int *visited;
};
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
        printf(" % d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((g[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf(" % d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}

void add(int item)
{
    if (rea == size - 1)
        printf("Queue is Full\n");
    else
    {
        if (rea == -1)
        {
            qu[++rea] = item;
            fro++;
        }
        else
            qu[++rea] = item;
    }
}
int delete ()
{
    int k;
    if ((fro > rea) || (fro == -1))
        return (0);
    else
    {
        k = qu[fro++];
        return (k);
    }
}

void push(int item)
{
    if (top == size - 1)
        printf("Stack overflow \n");
    else
        stack[++top] = item;
}

int pop()
{
    int k;
    if (top == -1)
        return (0);
    else
    {
        k = stack[top--];
        return (k);
    }
}

struct node *create_node(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *create_graph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;

    graph->adj_lists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adj_lists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void add_the_edge(struct Graph *graph, int src, int dest)
{

    struct node *newNode = create_node(dest);
    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;

    newNode = create_node(src);
    newNode->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = newNode;
}

struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int check_empty(struct queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int value)
{
    if (q->rear == size - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue *q)
{
    int item;
    if (check_empty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {

            q->front = q->rear = -1;
        }
    }
    return item;
}

void print(struct queue *q)
{
    int i = q->front;

    if (check_empty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}
void BFS(struct Graph *graph, int startVertex)
{
    struct queue *q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!check_empty(q))
    {
        print(q);
        int cur = dequeue(q);
        printf("Visited %d\n", cur);

        struct node *temp = graph->adj_lists[cur];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

bool bipartite_or_not(int graph[][size], int source)
{

    int colour[size];
    for (int i = 0; i < size; i++)
    {
        colour[i] = -1;
    }

    colour[source] = 1;

    struct queue *q = createQueue();

    enqueue(q, source);

    while (!check_empty(q))
    {

        int u = dequeue(q);

        if (graph[u][u] == 1)
            return false;

        for (int v = 0; v < size; ++v)
        {

            if (graph[u][v] && colour[v] == -1)
            {

                colour[v] = 1 - colour[u];
                enqueue(q, v);
            }

            else if (graph[u][v] && colour[v] == colour[u])
                return false;
        }
    }

    return true;
}

int main()
{
    int n, i, s, ch, j;
    char c;
    printf("\nWelcome to Assignment-8");
    printf("\n-------------------------------\n\n");
    printf("Enter the number of Vertices the Graph has\n");
    scanf("%d", &n);
    struct Graph *graph = create_graph(n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("\nEnter 1 if % d has a node with % d, else 0 \n", i, j);
            scanf("%d", &g[i][j]);
            if (g[i][j] == 1)
            {
                add_the_edge(graph, i - 1, j - 1);
            }
        }
    }
    printf("The Adjacency matrix is \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf(" % d", g[i][j]);
        }
        printf("\n");
    }
    printf("Enter the source vertex for finding the BFS Traversal for Adjacency Matrix\n");
    scanf("%d", &s);
    printf("The BFS Traversal of the Adjacency Matrix is \n");
    bfs(s, n);
    printf("\n");
    printf("The BFS Traversal of the Adjacency List is ");
    BFS(graph, 0);
    printf("\n");
    printf("The given Graph is Bipartite or not ?\n");
    bipartite_or_not(g, 0) ? printf("Yes, Graph is Bipartite\n") : printf("No, Graph is not Bipartite\n");

    return 0;
}
