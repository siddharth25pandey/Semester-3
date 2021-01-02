#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} Node;

Node *newNode(int key)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

int min(int a, int b)
{
    if (a == -1)
        return b;
    if (a <= b)
        return a;
    else
        return b;
}

Node *Insert(Node *items, int key)
{
    if (items == NULL)
        return newNode(key);

    else
    {
        Node *prev = newNode(key);
        prev->next = items;
        return prev;
    }
}

void Union(Node *items[], int cur, int pre, int key)
{
    items[cur] = newNode(key);
    items[cur]->next = items[pre];
}

void printItems(Node *items[], int i)
{
    Node *curr = items[i];
    while (curr != NULL)
    {
        if (curr->next == NULL)
            printf("%d ", curr->key);
        else
            printf("%d <-- ", curr->key);

        curr = curr->next;
    }
    printf("\n");
}

void Denomination(int n, int coin[], int C)
{
    Node *items = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        while (C >= coin[i])
        {
            C -= coin[i];
            items = Insert(items, coin[i]);
        }
    }

    Node *curr = items;
    while (curr != NULL)
    {
        printf("%d ", curr->key);
        curr = curr->next;
    }
    printf("\n");
}

void Planner(int val[], int n)
{
    int P[n + 1];
    Node *items[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        items[i] = NULL;
        P[i] = -1;
    }

    P[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (val[i] - val[j] <= 20)
            {
                int x = P[i];
                P[i] = min(P[i], P[j] + (20 - (val[i] - val[j])) * (20 - (val[i] - val[j])));
                if (P[i] != x && j != 0)
                    Union(items, i, j, j);
            }
        }
    }
    items[n] = Insert(items[n], n);
    printItems(items, n);
    printf("%d\n", P[n]);
}

int main()
{
    FILE *fp;
    char file[100];

    // Coin Denomination
    printf("Coin Denomination\n");
    printf("Enter the name of the file: \n");
    scanf("%s", file);

    fp = fopen(file, "r");

    int n;
    fscanf(fp, "%d", &n);
    int coin[n];
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &coin[i]);

    int m, q;
    fscanf(fp, "%d", &m);
    for (int j = 0; j < m; j++)
    {
        fscanf(fp, "%d", &q);
        Denomination(n, coin, q);
    }

    fclose(fp);

    printf("\n");

    // Travel and Stay Planner
    printf("Travel and Stay Planner\n");
    printf("Enter the name of the file: ");
    scanf("%s", file);

    fp = fopen(file, "r");

    fscanf(fp, "%d", &n);
    int val[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        fscanf(fp, "%d", &val[i]);
    }

    Planner(val, n);

    fclose(fp);

    return 0;
}