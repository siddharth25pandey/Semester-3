#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// Lab Assignment 12
// Siddharth Pandey
// S20190010163

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int zero_one_knapsack(int x, int b[], int c[], int n)
{

    int a[n + 1][x + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (i == 0 || j == 0)
            {
                a[i][j] = 0;
            }
            else if (b[i - 1] <= j)
            {
                a[i][j] = maximum(c[i - 1] + a[i - 1][j - b[i - 1]], a[i - 1][j]);
            }
            else
            {
                a[i][j] = a[i - 1][j];
            }
        }
    }

    return a[n][x];
}
int unbounded_knapsack(int x, int n, int c[], int b[])
{
    int a[x + 1];
    memset(a, 0, sizeof(a));

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[j] <= i)
            {
                a[i] = maximum(a[i], a[i - b[j]] + c[j]);
            }
        }
    }

    return a[x];
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
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &a[i]);
    }
    int x, w;
    fscanf(file, "%d", &x);
    int b[x];
    for (int i = 0; i < x; i++)
    {
        fscanf(file, "%d", &b[i]);
    }
    printf("Enter the size of Knapsack \n");
    scanf("%d", &w);

    int ch;
    while (1)
    {
        printf("\nEnter your choice:\n1)=> for Unbounded Knapsack(Reptition allowed) \t2)=> for 0-1 Knapsack\t3)=> for Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf("Maximum value that can be put in a knapsack of capacity %d is: %d ", w, unbounded_knapsack(w, n, a, b));
            break;
        case 2:
            printf("Maximum value that can be put in a knapsack of capacity %d is: %d ", w, zero_one_knapsack(w, b, a, n));
            break;
        case 3:
            printf("Thanks for Joining! Happy Coding :)\n");
            exit(0);
        default:
            printf("Please enter valid input\n");
            break;
        }
    }
    return 0;
}

// Sample Input from File
/*
3
10 30 20
3
5 10 15
*/
// Sample Output
/*
Enter the name of the file 
last.txt
Enter the size of Knapsack 
100

Enter your choice:
1)=> for Unbounded Knapsack(Reptition allowed)  2)=> for 0-1 Knapsack   3)=> for Exit
1
Maximum value that can be put in a knapsack of capacity 100 is: 300 
Enter your choice:
1)=> for Unbounded Knapsack(Reptition allowed)  2)=> for 0-1 Knapsack   3)=> for Exit
2
Maximum value that can be put in a knapsack of capacity 100 is: 60 
Enter your choice:
1)=> for Unbounded Knapsack(Reptition allowed)  2)=> for 0-1 Knapsack   3)=> for Exit
3
Thanks for Joining! Happy Coding :)
*/

/*
Enter the name of the file 
last.txt
Enter the size of Knapsack 
10

Enter your choice:
1)=> for Unbounded Knapsack(Reptition allowed)  2)=> for 0-1 Knapsack   3)=> for Exit
1
Maximum value that can be put in a knapsack of capacity 10 is: 30 
Enter your choice:
1)=> for Unbounded Knapsack(Reptition allowed)  2)=> for 0-1 Knapsack   3)=> for Exit
2
Maximum value that can be put in a knapsack of capacity 10 is: 30 
Enter your choice:
1)=> for Unbounded Knapsack(Reptition allowed)  2)=> for 0-1 Knapsack   3)=> for Exit
3
Thanks for Joining! Happy Coding :)

*/
