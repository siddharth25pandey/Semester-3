#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct company_structure
{

    struct company_strcuture *employ;
    struct company_strcuture *boss;
    struct company_strcuture *next;
    char name[100];
    int height;

} node;
node *root = NULL;
node **r = &root;
node *create_node()
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->employ = NULL;
    ptr->boss = NULL;
    ptr->next = NULL;
    return ptr;
}

node **search(node **ptr, char *e_name)
{
    if (strcmp((*ptr)->name, e_name) == 0)
    {
        return ptr;
    }
    else
    {
        ptr = &((*ptr)->employ);
        while ((*ptr) != NULL)
        {
            node **p = search(&(*ptr), e_name);
            if (p != NULL)
            {
                return p;
            }
            ptr = &((*ptr)->next);
        }
    }
    return NULL;
}
void AddEmployee(char *S, char *S1)
{
    node *new = create_node();
    strcpy(new->name, S);
    if (root == NULL)
    {
        root = new;
        root->height = 1;
        root->next = NULL;
        root->boss = NULL;
        root->employ = NULL;
    }
    else
    {
        node **ptr = search(r, S1);
        if (ptr == NULL)
        {
            printf("There is no Boss\n");
            return;
        }
        new->height = (*ptr)->height + 1;
        new->boss = (*ptr);
        ptr = &((*ptr)->employ);
        while ((*ptr) != NULL)
        {
            ptr = &((*ptr)->next);
        }
        (*ptr) = new;
    }
}
node **search_height(node **ptr, char *e_name, int level)
{
    if (strcmp((*ptr)->name, e_name) == 0 && (*ptr)->height == level)
    {
        return ptr;
    }
    else
    {
        ptr = &((*ptr)->employ);
        while ((*ptr) != NULL)
        {
            node **p = search_height(&(*ptr), e_name, level);
            if (p != NULL)
            {
                return p;
            }
            ptr = &((*ptr)->next);
        }
    }
    return NULL;
}

void Clear(char *S)
{
    node **ptr = search(r, S);
    (*ptr) = (*ptr)->next;
}
void DeleteEmployee(char *S, char *S1)
{
    node **ptr = search(r, S);
    node **ptr1 = search_height(r, S1, (*ptr)->height);

    if (ptr1 == NULL)
    {
        printf("Sorry but %s ,Cannot be deleted as there is no one else to take that responsibility.\n", (*ptr)->name);
    }
    else
    {
        ptr1 = &((*ptr1)->employ);
        while ((*ptr1) != NULL)
        {
            ptr1 = &((*ptr1)->next);
        }
        ptr = &((*ptr)->employ);
        while ((*ptr) != NULL)
        {
            (*ptr)->boss = (*ptr1);
            (*ptr1) = (*ptr);
            ptr1 = &((*ptr1)->next);
            ptr = &((*ptr)->next);
        }
        Clear(S);
    }
}

void LowestCommonBoss(char *S, char *S1)
{
    node **ptr = search(r, S);
    node **ptr1 = search(r, S1);
    while (((*ptr)->height) > ((*ptr1)->height))
    {
        ptr = &((*ptr)->boss);
    }
    while (((*ptr)->height) < ((*ptr1)->height))
    {
        ptr1 = &((*ptr1)->boss);
    }
    if (strcmp((*ptr)->name, (*ptr1)->name) == 0)
    {
        printf("The Lowest Common Boss is %s\n", (*ptr)->name);
    }
    else
    {
        while (strcmp((*ptr)->name, (*ptr1)->name) != 0)
        {
            ptr = &((*ptr)->boss);
            ptr1 = &((*ptr1)->boss);
        }
        printf("The Lowest Common Boss is %s\n", (*ptr)->name);
    }
}
void PrintEmployees(node **ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("The Employee name is '%s' and the level of the employ is  %d\n", (*ptr)->name, (*ptr)->height);
    node **flag = ptr;
    flag = &((*flag)->employ);
    while ((*flag) != NULL)
    {
        node **ptr1 = &(*flag);
        PrintEmployees(ptr1);
        flag = &((*flag)->next);
    }
}

int main()
{
    char s[100], s1[100];
    printf("Welcome to Company\n");
    printf("---------------------\n");
    int opt;
    while (1)
    {

        printf("\n 1) Add the Employee Name\n 2) Delete the Employee\n 3) Find the Lowest Common Boss\n 4) Print the Employee Details in BFS order\n 5) Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the Employee Name\n");
            scanf("%s", s);
            printf("\n");
            printf("Enter the boss name\n");
            printf("(If Employee has no Boss then Write 'BOSS' here, otherwise write the name of the Boss)\n");
            scanf("%s", s1);
            printf("\n");
            AddEmployee(s, s1);
            break;
        case 2:
            printf("Enter the Employee Name\n");
            scanf("%s", s);
            printf("\n");
            printf("Enter the Teammate Name\n");
            scanf("%s", s1);
            printf("\n");
            DeleteEmployee(s, s1);
            break;
        case 3:
            printf("Enter the Employee Name\n");
            scanf("%s", s);
            printf("\n");
            printf("Enter the other Employee Name\n");
            scanf("%s", s1);
            printf("\n");
            LowestCommonBoss(s, s1);
            break;
        case 4:
            PrintEmployees(r);
            break;
        case 5:
            printf("Thanks for Using, Happy Coding :)\n");
            exit(0);

            break;
        default:
            printf("Enter the valid Choice\n");
        }
    }
}