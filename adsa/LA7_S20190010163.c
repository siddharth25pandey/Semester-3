#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int visited;
} node;

void insert(struct node **, int);
void dfs_traversal_using_iterative_approach(struct node *);
void dfs_traversal_using_recursive_approach(struct node *);
void insert(node **head, int num)
{
    node *temp = *head, *prev = *head;

    if (*head == NULL)
    {
        *head = (node *)malloc(sizeof(node));
        (*head)->data = num;
        (*head)->visited = 0;
        (*head)->left = (*head)->right = NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if (num > temp->data)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (node *)malloc(sizeof(node));
        temp->data = num;
        temp->visited = 0;
        if (temp->data >= prev->data)
        {
            prev->right = temp;
        }
        else
        {
            prev->left = temp;
        }
    }
}

void dfs_traversal_using_iterative_approach(node *head)
{
    node *temp = head, *prev;

    printf("On DFS Iterative traversal we get:\n");
    while (temp && !temp->visited)
    {
        if (temp->left && !temp->left->visited)
        {
            temp = temp->left;
        }
        else if (temp->right && !temp->right->visited)
        {
            temp = temp->right;
        }
        else
        {
            printf("%d ", temp->data);
            temp->visited = 1;
            temp = head;
        }
    }
}
void dfs_traversal_using_recursive_approach(node *head)
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        return;
    }

    dfs_traversal_using_recursive_approach(ptr->left);

    dfs_traversal_using_recursive_approach(ptr->right);
    printf("%d ", ptr->data);
}

int main()
{
    node *head = NULL;
    int choice = 0, n;
    printf("Welcome to DFS Traversal\n\n");

    printf("Enter the number of vertices you want to insert: \n");
    int k;
    scanf("%d", &n);
    printf("Enter the node values\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        insert(&head, k);
    }

    while (1)
    {
        printf("\nDepth First Implementation");
        printf("\n-----------------------------\n");
        printf("1 DFS Iterative Traversal\n2 DFS Recursive Traversal\n3 Exit\n");
        printf("Enter your choice for DFS Traversal\n");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("DFS Iterative Traversal\n");
            dfs_traversal_using_iterative_approach(head);
            printf("\n");
            break;
        case 2:
            printf("DFS Recursive Traversal\n");
            dfs_traversal_using_recursive_approach(head);
            printf("\n");
            break;
        case 3:

            exit(0);
            break;
        default:
            printf("Enter the valid input\n");
        }
    }

    return 0;
}
