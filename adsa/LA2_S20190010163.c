#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
bool sort(int a[], int n)
{
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
        {
            return false;
        }
    }
    return true;
}

void shuffle(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        swap(&a[i], &a[rand() % n]);
    }
}
void bogo_sort(int a[], int n)
{

    while (!sort(a, n))
    {
        shuffle(a, n);
    }
}
void q1()
{
    clock_t begin = clock();
    int n, i;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bogo_sort(a, n);
    printf("The Elements of the Array after doing Bogo_Sort\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    clock_t end = clock();
    printf("Time taken:%lf sec\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

int part(int a[], int small, int big)
{
    int piv = a[small];
    int i = small - 1;
    int j = big + 1;
    while (true)
    {
        do
        {
            i++;

        } while (a[i] < piv);
        do
        {
            j--;
        } while (a[j] > piv);
        if (i >= j)
        {
            return j;
        }
        swap(&a[i], &a[j]);
    }
}
int part_r(int a[], int small, int big)
{
    srand(time(NULL));
    int x = small + rand() % (big - small);
    swap(&a[x], &a[small]);
    return part(a, small, big);
}
void rand_quick_sort(int a[], int small, int big)
{
    if (small < big)
    {
        int x = part_r(a, small, big);
        rand_quick_sort(a, small, x);
        rand_quick_sort(a, x + 1, big);
    }
}
void q2()
{
    clock_t begin = clock();
    int n, i;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    rand_quick_sort(a, 0, n - 1);
    printf("The Elements of the Array after doing Randomized Quick Sort\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    clock_t end = clock();
    printf("Time taken:%lf sec\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

int main()
{
    clock_t begin = clock();
    while (1)
    {
        int ch;
        printf("1==> For Bogo sort, 2==> For Randomized Quick Sort, 3==> Exit\n\n");
        printf("Enter the Choice number\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            q1();
            break;
        case 2:
            q2();
            break;
        case 3:
            exit(0);
        default:
            printf("Enter the valid choice number\n");
        }
    }

    clock_t end = clock();
    printf("Time taken:%lf sec\n", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}