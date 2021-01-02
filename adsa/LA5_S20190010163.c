
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct node
{
    struct node *c[26];
    int l;
} n;

n *create_node()
{
    n *ptr = (n *)malloc(sizeof(n));
    ptr->l = 0;
    for (int i = 0; i < 26; i++)
    {
        ptr->c[i] = NULL;
    }
    return ptr;
}
void insert(n *head, char *p)
{
    n *ptr = head;
    while (*p)
    {
        if (ptr->c[*p - 'a'] == NULL)
        {
            ptr->c[*p - 'a'] = create_node();
        }
        ptr = ptr->c[*p - 'a'];
        p++;
    }
    ptr->l = 1;
}
int child(n *ptr)
{
    for (int i = 0; i < 26; i++)
    {
        if (ptr->c[i])
        {
            return 1;
        }
    }
    return 0;
}
bool is_node(n *root)
{
    return root->l != false;
}
void display(n *root, char p[], int level)
{
    if (is_node(root))
    {
        p[level] = '\0';
        printf("%s", p);
        printf("\n");
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->c[i])
        {
            p[level] = i + 'a';
            display(root->c[i], p, level + 1);
        }
    }
}
int delete (n **ptr, char *p)
{

    if (*ptr == NULL)
    {
        printf("Trie is Empty\n");
        return 0;
    }
    if (*p)
    {
        if (*ptr != NULL && (*ptr)->c[*p - 'a'] != NULL && delete (&((*ptr)->c[*p - 'a']), p + 1) && (*ptr)->l == 0)
        {
            if (!child(*ptr))
            {
                free(*ptr);
                (*ptr) = NULL;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if (*p == '\0' && (*ptr)->l)
    {
        if (!child(*ptr))
        {
            free(*ptr);
            (*ptr) = NULL;
            return 1;
        }
        else
        {
            (*ptr)->l = 0;
            return 0;
        }
    }
    return 0;
}

int search(n *head, char *p)
{
    if (head == NULL)
    {
        printf("The Trie is Empty\n");
    }
    n *ptr = head;
    while (*p)
    {
        ptr = ptr->c[*p - 'a'];
        if (ptr == NULL)
        {
            return 0;
        }
        p++;
    }
    return ptr->l;
}
int main()
{
    n *head = create_node();
    char a[100000];
    char b[100000];
    int x = 0;
    printf("Taking Input from the File .......\n");
    printf("Texts from the file are inserted. Now Continue your Operation\n");
    printf("\n\n\n");
    FILE *f = fopen("a.txt", "r"); // Input taken from the a.txt file
    while (fscanf(f, "%s", b) == 1)
    {
        insert(head, b);
    }
    fclose(f);
    while (true)
    {
        printf("Trie Data Structure Implementation\n");
        printf("-------------------------------------\n");
        printf("1) Insert string\t 2)Delete string\t 3) Display\t 4) Search\t 5) Exit\n");
        printf("Enter your choice number\n");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:

            printf("Enter your string in (Lower_Case) for Insertion \n");
            scanf("%s", a);
            insert(head, a);
            printf("String Inserted Successfully\n");
            printf("\n");
            break;
        case 2:

            printf("Enter your string for Deletion\n");
            scanf("%s", a);
            delete (&head, a);
            printf("The String is Successfully deleted\n");
            printf("\n\n");
            break;
        case 3:
            printf("The words present in Trie Data structure are\n");
            display(head, a, x);
            printf("\n\n");
            break;
        case 4:
            printf("Enter your string for Searching\n");
            scanf("%s", a);
            int p = search(head, a);
            if (p == 0)
            {
                printf("The String is not Found\n");
            }
            else
            {
                printf("The String is Found\n");
            }
            printf("\n\n");
            break;
        case 5:
            printf("Thanks for joining. Happy Coding! :)\n");
            exit(0);
            break;
        default:
            printf("Please enter a valid number\n");
            break;
        }
    }

    return 0;
}