#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ADVANCED DATA STRUCTURE & ALGORITHM
ASSIGNMENT -5
SIDDHARTH PANDEY
S20190010163
*/

typedef struct flight_problem
{
    int key;
    int w;
    char flight[20];
    char departure[5];
    char arrival[5];
    struct flight_problem *next;
} node;

node *create_node(int x, int z, char name[], char s1[], char s2[])
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->key = x;
    ptr->w = z;
    strcpy(ptr->flight, name);
    strcpy(ptr->departure, s1);
    strcpy(ptr->arrival, s2);
    ptr->next = NULL;
    return ptr;
}

void insert(node *graph[], int size, int a, int b, char name[], char s1[], char s2[], int c)
{
    if (a > size)
    {
        printf("Sufficent information regarding the vertex is not present\n");
        return;
    }
    node *previous = graph[a];
    node *current = graph[a]->next;
    while (current != NULL)
    {
        previous = current;
        current = current->next;
    }
    previous->next = create_node(b, c, name, s1, s2);
}

int minimum_index(int n, int cost[], int visited[])
{
    int min = INT_MAX, ind;
    for (int k = 0; k < n; k++)
    {
        if (visited[k] == 0 && cost[k] <= min)
        {
            min = cost[k];
            ind = k;
        }
    }
    return ind;
}

int add_time(int s1, int s2)
{
    int m = s1 % 100;
    int h = s1 / 100;
    m += s2;
    if (m > 60)
    {
        m = m % 60;
        h += 1;
    }
    if (h > 23)
    {
        h = h % 23;
    }
    return (h * 100 + m);
}

void cheapest_trip(node *graph[], int n, int s, int d, char dep[], char a[])
{
    int visited[n];
    int cost[n];
    int time[n];
    for (int k = 0; k < n; k++)
    {
        visited[k] = 0;
        cost[k] = 100000;
        time[k] = 2400;
    }
    cost[s] = 0;
    time[s] = atoi(dep);

    for (int k = 0; k < n; k++)
    {
        int x = minimum_index(n, cost, visited);
        node *current = graph[x]->next;
        visited[x] = 1;
        while (current != NULL)
        {
            if (visited[current->key] == 0 && time[x] <= atoi(current->departure) && atoi(current->arrival) <= atoi(a) && cost[current->key] > cost[x] + current->w)
            {
                cost[current->key] = cost[x] + current->w;
                time[current->key] = add_time(atoi(current->arrival), 30);
            }
            current = current->next;
        }
    }

    printf("The Cheapest Cost for the Trip is : %d\n", cost[d]);
}

int main()
{
    FILE *file;
    char string[100];

    printf("Enter the name of the file \n");
    scanf("%s", string);

    file = fopen(string, "r");

    int n;
    fscanf(file, "%d", &n);

    node *graph[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = create_node(i + 1, 0, "", "0000", "0000");
    }

    int p;
    fscanf(file, "%d", &p);
    int a, b, c;
    char s1[5], s2[5];
    for (int j = 0; j < p; j++)
    {
        fscanf(file, "%d %d %s %s %s %d", &a, &b, s1, s2, string, &c);
        insert(graph, n, a - 1, b - 1, string, s1, s2, c);
    }

    int r;
    fscanf(file, "%d", &r);

    for (int k = 0; k < r; k++)
    {
        fscanf(file, "%d %d %s %s", &a, &b, s1, s2);
        cheapest_trip(graph, n, a - 1, b - 1, s1, s2);
    }

    fclose(file);

    return 0;
}

/* Sample Input
   ------------
   # Put the below Input in a Txt File
4
10
1 2 1200 1300 a 12000
2 3 1330 1500 b 13000
1 2 1000 1200 c 14000
3 1 1600 1800 d 15000
1 3 0900 1300 e 20000
2 4 1300 1600 f 10000
2 4 1730 1900 g 10000
3 4 1530 1700 h 11000
4 3 1200 1530 i 9000
1 4 0900 1700 j 12000
7
1 2 0900 1500
1 3 1100 1600
1 3 0900 1600
2 1 1200 2000
1 2 1100 1500
1 4 0900 2000
4 1 1000 2000
*/
/*
Sample Output
--------------
Enter the name of the file 
lab.txt
The Cheapest Cost for the Trip is : 12000
The Cheapest Cost for the Trip is : 25000
The Cheapest Cost for the Trip is : 20000
The Cheapest Cost for the Trip is : 28000
The Cheapest Cost for the Trip is : 12000
The Cheapest Cost for the Trip is : 12000
The Cheapest Cost for the Trip is : 24000
*/