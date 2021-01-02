#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*
ADVANCED DATA STRUCTURE & ALGORITHM
ASSIGNMENT -13
SIDDHARTH PANDEY
S20190010163
*/
// use gcc file.c -lm for compilation due to inclusion of math library

int coin_denomination(int number_of_coins[], int z, int value)
{
    int i, j, k;
    int a[value + 1];

    a[0] = 0;

    for (i = 1; i <= value; i++)
    {
        a[i] = INT_MAX;
    }

    for (int k = 1; k <= value; k++)
    {
        for (int j = 0; j < z; j++)
            if (number_of_coins[j] <= k)
            {
                int x = a[k - number_of_coins[j]];
                if (x != INT_MAX && x + 1 < a[k])
                    a[k] = x + 1;
            }
    }

    return a[value];
}

void print_the_path(int a[], int k)
{
    if (k == 0)
    {
        return;
    }
    print_the_path(a, a[k]);
    printf("%d ", k);
}
int planner(int a[], int n)
{
    int op[n], i, j, k;
    op[0] = 0;
    op[1] = 0;
    int penalty[n];
    penalty[0] = 0;
    penalty[1] = pow(200 - a[1], 2);
    for (i = 2; i < n; i++)
    {
        op[i] = -1;
        penalty[i] = -1;
    }
    for (i = 2; i <= n - 1; i++)
    {
        for (j = 0; j < i; j++)
        {
            int x = (int)(penalty[j] + pow(200 - (a[i] - a[j]), 2));
            if (penalty[i] == -1 || x < penalty[i])
            {
                penalty[i] = x;
                op[i] = j;
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        printf("Hotel: %d, penalty: %d, path : ", a[k], penalty[k]);
        print_the_path(op, k);
        printf("\n");
    }
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
    int a[n];

    for (int j = 0; j < n; j++)
    {
        fscanf(file, "%d", &a[j]);
    }

    int r, p;
    time_t t1, t2;

    fscanf(file, "%d", &p);
    for (int k = 0; k < p; k++)
    {
        fscanf(file, "%d", &r);
        t1 = clock();
        printf("Minimum Coin Required is %d\n", coin_denomination(a, n, r));
        t2 = clock();
        printf("Running time: %f seconds \n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    }

    fclose(file);

    FILE *file1;
    char string1[100];

    printf("Enter the name of the file \n");
    scanf("%s", string1);

    file1 = fopen(string1, "r");

    int n1;
    fscanf(file, "%d", &n1);
    int b[n1];

    for (int j = 0; j < n1; j++)
    {
        fscanf(file1, "%d", &b[j]);
    }
    printf("%d", planner(b, n1));
    printf("\n");
    fclose(file1);

    return 0;
}

// File Input-1
/*
4
1 5 6 9
4
11
3
4
6
*/
// File Input-2
/*
6
10
20
35
60
70
90
*/
