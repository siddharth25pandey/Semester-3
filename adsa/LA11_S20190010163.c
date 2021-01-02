#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef struct ed
{
    int from, dest, wt;
} ed;

void bellman(int nv, ed e[], int src_graph, int ne, int size)
{
    int u, v, weight, i, j = 0;
    int arr[size];

    for (i = 0; i < nv; i++)
    {

        arr[i] = INT_MAX;
    }
    arr[src_graph] = 0;
    for (i = 0; i < nv - 1; i++)
    {
        for (j = 0; j < ne; j++)
        {
            u = e[j].from;
            v = e[j].dest;
            weight = e[j].wt;
            if (arr[u] != 999 && arr[u] + weight < arr[v])
            {
                arr[v] = arr[u] + weight;
            }
        }
    }

    /* check for negative cycle*/
    for (j = 0; j < ne; j++)
    {
        u = e[j].from;
        v = e[j].dest;
        weight = e[j].wt;

        if (arr[u] + weight < arr[v])
        {

            printf("\n\nThere is a NEGATIVE CYCLE!!\n");
            return;
        }
    }

    printf("\nOutput\n");
    printf("\nVertex  Distance from the Source");

    for (i = 1; i <= nv; i++)
    {

        printf("\n%d\t %d", i, arr[i]);
    }
}

int main()
{
    int nv, ne, src_graph, size;

    printf("Enter the max size of the array:\n");

    scanf("%d", &size);
    ed e[size];

    printf("Enter the number of vertices: \n");

    scanf("%d", &nv);
    printf("Enter the source vertex: \n");

    scanf("%d", &src_graph);

    printf("Enter the number of edges:  \n");

    scanf("%d", &ne);

    for (int i = 0; i < ne; i++)
    {

        printf("Edge %d =>\n", (i + 1));

        printf("Enter the source vertex\n");

        scanf("%d", &e[i].from);
        printf("Enter the destination vertex\n");

        scanf("%d", &e[i].dest);

        printf("Enter the Weight : \n");

        scanf("%d", &e[i].wt);
    }

    bellman(nv, e, src_graph, ne, size);
    printf("\n");
    return 0;
}
//Main function ends

/*Sample Input Output
Enter the max size of the array:
10
Enter the number of vertices: 
4
Enter the source vertex: 
1
Enter the number of edges:  
4
Edge 1 =>
Enter the source vertex
1
Enter the destination vertex
2
Enter the Weight : 
4
Edge 2 =>
Enter the source vertex
1
Enter the destination vertex
3
Enter the Weight : 
3
Edge 3 =>
Enter the source vertex
2
Enter the destination vertex
4
Enter the Weight : 
7
Edge 4 =>
Enter the source vertex
3
Enter the destination vertex
4
Enter the Weight : 
-2

Output

Vertex  Distance from the Source
1        0
2        4
3        3
4        1

Time Complexity : O(V*E)
where V is no. of vertices and E is no. of edges in the graph.
*/