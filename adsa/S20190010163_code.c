#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
/*
SIDDHARTH PANDEY
S20190010163
FINAL ADSA LAB EXAM
*/

int max(int a, int b) // Finding out the Maximum of two numbers
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void q2()
{
    int n; // Declaring the size of the array
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int a[n]; // Declaring the Array of size n
    printf("Enter the elements of the sequence\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int increment = 1; // Declaring the variable for counting the increment
    int decrement = 1; // Declaring the variable for counting the decrement
    // Both are initialised with 1 because the sinlge element is still a Longest Alternating Subsequence

    for (int k = 1; k < n; k++) // Iterating the for loop from the second element
    {
        if (a[k] > a[k - 1])
        {
            increment = decrement + 1; // Increment changes when decrement changes
        }
        else if (a[k] < a[k - 1])
        {
            decrement = increment + 1; // Decrement changes when decrement changes
        }
    }
    int ans = max(increment, decrement); // Finally printing the Maximum length from increment and decrement
    printf("The Length of the Longest Alternating Subsequence is: %d  \n", ans);
}
void q2_dp()
{
    int n; // Declaring the size of the array
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int a[n]; // Declaring the Array of size n
    printf("Enter the elements of the sequence\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    /*las[i][0] = Length of the longest alternating subsequence
          ending at index i and last element is greater
          than its previous element
     las[i][1] = Length of the longest alternating subsequence
          ending at index i and last element is smaller
          than its previous element   */
    int last[n][2];

    /* Initialize all values from 1  */
    for (int i = 0; i < n; i++)
        last[i][0] = last[i][1] = 1;

    int ans = 1; // Initialize result

    /* Compute values in bottom up manner */
    for (int i = 1; i < n; i++)
    {
        // Consider all elements as previous of a[i]
        for (int j = 0; j < i; j++)
        {
            // If a[i] is greater, then check with last[j][1]
            if (a[j] < a[i] && last[i][0] < last[j][1] + 1)
                last[i][0] = last[j][1] + 1;

            // If a[i] is smaller, then check with last[j][0]
            if (a[j] > a[i] && last[i][1] < last[j][0] + 1)
                last[i][1] = last[j][0] + 1;
        }

        /* Pick maximum of both values at index i  */
        if (ans < max(last[i][0], last[i][1]))
        {
            ans = max(last[i][0], last[i][1]);
        }
    }

    printf("The Length of the Longest Alternating Subsequence is: %d  \n", ans);
}

// Alternating Subsequence Problem -2
int main()
{
    while (1)
    {
        printf("FINAL ADSA END LAB EXAM (SIDDHARTH PANDEY)\n");
        printf("---------------------\n");
        printf(" 1)=>  Question -2 (Longest Alternating Subsequence) optimal solution,\n 2)=>Question -2 (Longest Alternating Subsequence using DP),\n 3) => Exit \n");
        int op;
        printf("Enter your choice\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            q2();
            printf("\n");
            break;
        case 2:
            q2_dp();
            printf("\n");
            break;
        case 3:
            printf("Thanks for joining, Happy Coding :) \n");
            exit(0);

            break;
        default:
            printf("Please enter valid input\n");
        }
    }
    return 0;
}
