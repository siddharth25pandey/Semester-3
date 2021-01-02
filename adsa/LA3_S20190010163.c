#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void radix(int a[], int n, int z, int exp)
{
    int b[n], bucket[z];
    int i;
    for (i = 0; i < z; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        bucket[(a[i] / exp) % z]++;
    }
    for (i = 1; i < z; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        b[bucket[(a[i] / exp) % z] - 1] = a[i];
        bucket[(a[i] / exp) % z]--;
    }

    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void radix_sort(int a[], int n, int z)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }

    for (int exp = 1; m / exp > 0; exp *= z)
    {
        radix(a, n, z, exp);
    }
}
void q1()
{
    int x, n, i, j;
    clock_t begin = clock();
    printf("Enter the number of Buckets or base\n");
    scanf("%d", &x);
    printf("Enter the number of elements you want to insert\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The Array elements before Sorting\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    radix_sort(a, n, x);
    printf("The Array elements after Radix Sort\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    clock_t end = clock();
    printf("Time Taken: %lf sec\n ", (double)(end - begin) / CLOCKS_PER_SEC);
}

typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;

} node;

node *root = NULL;

void insert(int x)
{
    node *p = root;
    node *q, *temp;
    temp = (node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->lchild = temp->rchild = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while (p != NULL)
        {
            q = p;
            if (p->data == x)
            {
                return;
            }
            else if (x < p->data)
            {
                p = p->lchild;
            }
            else
            {
                p = p->rchild;
            }
        }
        if (x > q->data)
        {
            q->rchild = temp;
        }
        else
        {
            q->lchild = temp;
        }
    }
}

void search(node *p, int x)
{
    if (p == NULL)
    {
        printf("Binary Search Tree is Empty\n");
    }
    else
    {
        while (p != NULL)
        {
            if (p->data == x)
            {
                printf("Element is Found\n");
                return;
            }
            else if (x < p->data)
            {
                p = p->lchild;
            }
            else
            {
                p = p->rchild;
            }
        }
    }
    printf("Element not found in the BST\n");
}

void inorder(node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d -> ", p->data);
        inorder(p->rchild);
    }
}
int height(node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

node *inorder_predecssor(node *p)
{
    while (p && p->rchild != NULL)

    {
        p = p->rchild;
    }
    return p;
}
node *inorder_successor(node *p)
{
    while (p && p->lchild != NULL)

    {
        p = p->lchild;
    }
    return p;
}
node *delete (node *p, int x)
{
    node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        free(p);
        return NULL;
    }
    if (x < p->data)
    {
        p->lchild = delete (p->lchild, x);
    }
    else if (x > p->data)
    {
        p->rchild = delete (p->rchild, x);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = inorder_predecssor(p->lchild);
            p->data = q->data;
            p->lchild = delete (p->lchild, q->data);
        }
        else
        {
            q = inorder_successor(p->rchild);
            p->data = q->data;
            p->rchild = delete (p->rchild, q->data);
        }
    }

    return p;
}

void q2()
{
    int n, data;
    int ch;
    int x, y;
    while (1)
    {
        printf("Binary Search Tree\n");
        printf("1) Insertion in BST, 2) Deletion of any element, 3) Displaying the BST in Inorder Traversal, 4) Searching, 5) Exit\n");
        printf("Enter your Choice number\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number of data to be inserted in Binary Search Tree\n");
            scanf("%d", &n);
            printf("Enter the node values\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                insert(data);
            }
            printf("Elements are inserted Successfully\n");
            break;
        case 2:
            printf("Enter the node value to be deleted from the node\n");
            scanf("%d", &y);
            delete (root, y);
            printf("Elements is deleted Successfully\n");
            break;
        case 3:
            printf("Elements in the BST are in Inorder Traversal are\n");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter any element to search in the Binary Search Tree\n");
            scanf("%d", &x);
            search(root, x);
            break;
        case 5:
            printf("Thanks for joining. Happy Coding !\n");
            exit(0);

            break;
        default:
            printf("Please input a valid choice number\n");
        }
    }
}

int main()
{
    while (1)
    {
        printf("1) For Radix Sort, 2) For Binary Search Tree, 3) Exit\n");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            q1();
            printf("\n");
            break;
        case 2:
            q2();
            printf("\n");
            break;
        case 3:
            printf("Thanks for joining. Happy Coding !\n");
            exit(0);
            break;
        default:
            printf("Please input a valid choice number\n");
        }
    }
    return 0;
}

//Sample Input for Question-1
// --------------------------
/*Enter the number of Buckets or base
4
Enter the number of elements you want to insert
2
Enter the elements
3 2 
The Array elements before Sorting
3 2 
The Array elements after Radix Sort
2 3 
Time Taken: 0.000318 sec*/

/*Enter the number of Buckets or base
6
Enter the number of elements you want to insert
8
Enter the elements
2 30 56 1 989 45 26 100
The Array elements before Sorting
2 30 56 1 989 45 26 100 
The Array elements after Radix Sort
1 2 26 30 45 56 100 989 
Time Taken: 0.000340 sec*/

/*Enter the number of Buckets or base
8
Enter the number of elements you want to insert
15
Enter the elements
2 8 36 4 5 25 52 100 9 78 11 56 84 96 53265
The Array elements before Sorting
2 8 36 4 5 25 52 100 9 78 11 56 84 96 53265 
The Array elements after Radix Sort
2 4 5 8 9 11 25 36 52 56 78 84 96 100 53265 
Time Taken: 0.000403 sec*/
