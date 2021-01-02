#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
int size = 0;
int max = 10;
typedef struct item
{
    int key;
    int value;
    struct item *point;
} hash;

typedef struct hashtable_item
{
    int count;
    hash *data;
} hashtable;

hashtable *array;

void normal_hashing_insert(int key, int value)
{
    int index = key % max;
    int i = index, h = 1;

    hash *new_item = (hash *)malloc(sizeof(hash));
    new_item->key = key;
    new_item->value = value;

    while (array[i].count == 1)
    {
        i = (key + (h * h)) % max;
        h++;
        if (i == index)
        {
            printf("\n Hash table is full, cannot insert any more data \n");
            return;
        }
    }

    array[i].count = 1;
    array[i].data = new_item;
    size++;
    printf("\n The Value (%d) for  Key (%d) has been inserted Successfully\n", value, key);
}
hash *create_node(int x)
{
    hash *node = (hash *)malloc(sizeof(hash));
    node->value = x;
    node->point = NULL;
    return node;
}

void univeral_hashing_insert(hash *table[], int x, int z)
{
    hash *chain = create_node(x);

    if (table[z] == NULL)
        table[z] = chain;
    else
    {
        hash *traverse = table[z];
        while (traverse->point != NULL)
            traverse = traverse->point;
        traverse->point = chain;
    }
}

bool universal_hashing_search(hash *table[], int z, int x)
{
    if (table[z] == NULL)
        return false;
    else
    {
        hash *move = table[z];

        while (move != NULL && move->value != x)
        {
            move = move->point;
        }
        if (move != NULL)
            return true;
        else
            false;
    }
}

bool prime(int n)
{
    int i;
    for (i = 2; i < (n / 2); ++i)
    {
        if (!(n % i))
            return false;
    }
    return true;
}

void universal_hash_function(int s)
{
    int p = s + 1, a, b, ind, buckets, bucket;
    while (!prime(p))
        ++p;
    a = 1 + rand() % (p - 1);
    b = rand() % p;
    buckets = p;

    int i, n, found = 0;
    clock_t tme;
    double total_time, avg_time, std;
    n = 100;
    double time[n];

    hash *table[buckets];
    int U[size];

    for (i = 0; i < buckets; i++)
        table[i] = NULL;

    for (i = 0; i < size; ++i)
    {
        U[i] = rand() % 10000;
        bucket = ((a * U[i] + b) % p) % s;
        univeral_hashing_insert(table, U[i], bucket);
    }

    for (i = 0; i < n; ++i)
    {
        tme = clock();
        ind = rand() % size;
        bucket = ((a * U[ind] + b) % p) % size;
        if (universal_hashing_search(table, bucket, U[ind]))
            ++found;
        tme = clock() - tme;

        time[i] = ((double)tme) / CLOCKS_PER_SEC;
        total_time += time[i];
    }

    avg_time = total_time / n;
    i = n;
    while (i--)
        std += pow(time[i] - avg_time, 2);
    std = sqrt(std / n);

    printf("\nhash table for %d elements\n\n", size);
    printf("\nAverage Time = %f seconds\nStandard deviation = %f seconds\n\n", avg_time, std);
}

void display()
{
    clock_t begin = clock();
    printf("The Data Present in the Hash Table Along with the keys are\n");
    printf("\nX-----------------------------------------------------------------\n");
    for (int i = 0; i < max; i++)
    {
        printf("| %d\t |", i);
        if (array[i].data != NULL)
            printf(" %d %d ", array[i].data->key, array[i].data->value);
        printf("\n");
    }
    printf("\n-----------------------------------------------------------------X\n");
    clock_t end = clock();
    printf("Time taken:%lf sec\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

void search(int key)
{

    int index = key % max;
    int i = index, h = 1;

    while (array[i].count != 0)
    {

        if (array[i].count == 1 && array[i].data->key == key)
        {
            int m = array[i].data->value;
            printf("\n Key (%d) has been found whose value is %d\n", key, m);
            return;
        }

        i = (i + (h * h)) % max;
        h++;
        if (i == index)
            break;
    }
    printf("\n This key does not exist \n");
}

int main()
{
    int choice, key, value, n, x, z;
    int k = 0;
    array = (hashtable *)malloc(max * sizeof(hashtable));
    for (int i = 0; i < max; i++)
    {
        array[i].count = 0;
        array[i].data = NULL;
    }

    clock_t begin = clock();

    while (true)
    {
        printf("Welcome to the World Of Hashing\n");
        printf("------------------------------------\n");

        printf("\n1=> For Normal Hashing\t 2=> For Universal Hashing\t3==> For Exit\n\n");
        if (k == 0)
        {
            printf("\nFirst Visit Normal Hashing then Univeral Hashing\n\n");
        }
        printf("Enter your choice number\n");
        k = 1;
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            while (true)
            {
                printf("\n\nWelcome to Normal Hashing\n");
                printf("\nx-----------------------------------------------------------------x\n");
                printf("\n1==> For Inserting\t 2==> For searching \t3==> For Displaying the Hash Table\t 4==> For Exit from Normal Hashing\n\n");
                int o;
                printf("Enter your choice number\n");
                scanf("%d", &o);
                if (o == 4)

                {
                    printf("Moving Back to Main Program ...\n");
                    break;
                }
                else
                {
                    switch (o)
                    {
                    case 1:

                        printf("How may keys you want to enter ?\n");
                        scanf("%d", &x);
                        printf("Inserting element in Hashtable\n");
                        while (x--)
                        {
                            printf("Enter key and value-:\t");
                            scanf("%d %d", &key, &value);
                            normal_hashing_insert(key, value);
                        }
                        break;
                    case 2:
                        printf("Enter key for searching\n");
                        scanf("%d", &key);
                        search(key);
                        clock_t end = clock();
                        printf("Time taken:%lf sec\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        break;
                    }
                }
            }
        }
        else if (op == 2)
        {
            printf("\nWelcome to Universal Hashing\n");
            printf("\n-------------------------------\n");
            printf("Inputs are taken randomly\n");
            universal_hash_function(5);
            universal_hash_function(10);
            universal_hash_function(100);
            universal_hash_function(500);
            universal_hash_function(1000);
            printf("Enter the size you want to check for Universal hash Table\n");
            scanf("%d", &z);
            universal_hash_function(z);
        }
        else if (op == 3)
        {
            printf("Thanks for joining, Happy Coding :)\n");
            exit(0);
        }
        else
        {
            printf("Please enter valid input\n");
        }
    }

    return 0;
}