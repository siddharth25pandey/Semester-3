#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
    int source, destination, weight;
} Edge;
typedef struct Graph
{

    int V, E;
    Edge *edge;
} Graph;

Graph *create_graph(int g_vertex, int g_edge)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = g_vertex;
    graph->E = g_edge;

    graph->edge = (Edge *)malloc(g_edge * sizeof(Edge));

    return graph;
}

typedef struct subset
{
    int parent;
    int rank;
} subset;

int search(subset subsets[], int i)
{

    if (subsets[i].parent != i)
        subsets[i].parent = search(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void total(subset subsets[], int p, int q)
{

    int a = search(subsets, p);
    int b = search(subsets, q);

    if (subsets[a].rank < subsets[b].rank)
    {
        subsets[a].parent = b;
    }
    else if (subsets[a].rank > subsets[b].rank)
    {
        subsets[b].parent = a;
    }
    else
    {
        subsets[b].parent = a;
        subsets[a].rank++;
    }
}
int comapare(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}
void MST_by_using_Kruskals_Algorithm(Graph *graph)
{
    int g_vertex = graph->V;
    Edge res[g_vertex];
    int i = 0, e = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comapare);

    subset *subsets =
        (subset *)malloc(g_vertex * sizeof(subset));

    for (int k = 0; k < g_vertex; k++)
    {
        subsets[k].parent = k;
        subsets[k].rank = 0;
    }

    while (e < g_vertex - 1 && i < graph->E)
    {

        Edge next_edge = graph->edge[i++];

        int x = search(subsets, next_edge.source);
        int y = search(subsets, next_edge.destination);

        if (x != y)
        {
            res[e++] = next_edge;
            total(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree using Kruskals Algorithm is \n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d <==> %d\n", res[i].source + 1, res[i].destination + 1,
               res[i].weight);
    return;
}

int main()
{

    int g_vertex, g_edge;
    printf("\nWelcome to Kruskals Minimum Spanning Tree Algorithm");
    printf("\n-------------------------------------------------------\n\n");
    printf("\nEnter the number of vertices of the Adjacency List Graph\n");
    scanf("%d", &g_vertex);

    printf("Enter the number of Edges of the Adjacency List Graph\n");
    scanf("%d", &g_edge);
    Graph *graph = create_graph(g_vertex, g_edge);

    for (int i = 0; i < g_edge; i++)
    {
        int s, d;
        printf("Enter the Source Vertex between 1 to %d \n", g_vertex);
        scanf("%d", &s);
        printf("Enter the Destination Vertex between 1 to %d \n", g_vertex);
        scanf("%d", &d);
        graph->edge[i].source = s - 1;
        graph->edge[i].destination = d - 1;
        printf("Enter the Weight from Source Vertex %d to Destination Vertex %d is:\n", s, d);
        int w;
        scanf("%d", &w);
        graph->edge[i].weight = w;
    }

    MST_by_using_Kruskals_Algorithm(graph);

    return 0;
}