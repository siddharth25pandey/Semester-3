#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void q1()
{

    void sort(int a[], int n)
    {
        for (int i = 0; i < n; i++)

        {
            int min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[min_index])
                {
                    min_index = j;
                }
            }
            swap(&a[i], &a[min_index]);
        }
    }

    int p;
    printf("Enter the size of the array\n");
    scanf("%d", &p);
    int b[p];
    printf("Enter the elements of the array\n");
    for (int k = 0; k < p; k++)
    {
        scanf("%d", &b[k]);
    }
    sort(b, p);
    printf("The elements after sorting is\n");
    for (int k = 0; k < p; k++)
    {
        printf("%d ", b[k]);
    }
    printf("\n");
}
void q2a()
{
    printf("Enter the total number of user who are using any site\n");
    int n, z = 0;
    scanf("%d", &n);
    int arrival_time[n], leaving_time[n];
    printf("Enter the arrival & leaving time of each user in format (arrival & leaving time)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arrival_time[i], &leaving_time[i]);
    }
    printf("The Number of the pairs of users who are using the site at the same time are: \n");
    for (int j = 0; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if ((arrival_time[k] >= arrival_time[j] && arrival_time[k] <= leaving_time[j]) || (arrival_time[j] >= arrival_time[k] && arrival_time[j] <= leaving_time[k]))
            {
                printf("(%d,%d) \n", j + 1, k + 1);
                z++;
            }
        }
    }
    printf("The Total number of distinct pair of user which are possible is equal to %d\n", z);
}
void q2b()
{
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);

            heapify(arr, n, largest);
        }
    }
    void heapsort(int arr[], int n)
    {

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {

            swap(&arr[0], &arr[i]);

            heapify(arr, i, 0);
        }
    }

    printf("Enter the total number of user who are using any site\n");
    int n, z = 0;
    scanf("%d", &n);
    int arrival_time[n], leaving_time[n];

    printf("Enter the arrival & leaving time of each user in format (arrival & leaving time)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arrival_time[i], &leaving_time[i]);
    }
    heapsort(arrival_time, n);
    heapsort(leaving_time, n);
    printf("The Number of the pairs of users who are using the site at the same time are: \n");
    for (int j = 0; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (leaving_time[j] > arrival_time[k])
            {
                printf("(%d,%d) \n", j + 1, k + 1);
                z++;
            }
        }
    }
    printf("The Total number of distinct pair of user which are possible is equal to %d\n", z);
}
void q3c()
{
    printf("Enter the size of the array\n");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int minimum_element = a[0];
    for (int j = 0; j < n; j++)
    {
        if (a[j] <= minimum_element)
        {
            minimum_element = a[j];
        }
    }
    printf("The Minimum element of the array is %d\n", minimum_element);
}
void q3f()
{
    int min_array(int a[], int n)
    {
        if (n == 1)
        {
            return a[0];
        }
        int min_element = a[0];
        int x = min_array(a + 1, n - 1);
        if (min_element > x)
        {
            min_element = x;
        }
        return min_element;
    }
    printf("Enter the size of the array\n");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The Minimum element of the array is %d\n", min_array(a, n));
}
void q4aiv()
{
    int local_minima(int a[], int low, int high, int n)
    {
        int middle = low + (high - low) / 2;
        if ((middle == 0 || a[middle - 1] > a[middle]) && (middle == n - 1 || a[middle + 1] > a[middle]))
        {
            return middle;
        }
        else if ((middle > 0) && (a[middle - 1] < a[middle]))
        {
            return local_minima(a, low, (middle - 1), n);
        }
        return local_minima(a, (middle + 1), high, n);
    }
    printf("Enter the size of the array\n");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = local_minima(a, 0, n - 1, n);
    printf("The value of the Local Minima at index  %d is %d (if indexing starts from 1)\n", ans + 1, a[ans]);
}
void q4biv()
{
    int local_minima(int n, int arr[n][n], int low, int high)
    {
        if ((high == 0 || arr[low][high - 1] > arr[low][high]) && (high == n - 1 || arr[low][high + 1] > arr[low][high]) &&
            (low == 0 || arr[low - 1][high] > arr[low][high]) && (low == n - 1 || arr[low + 1][high] > arr[low][high]))
        {
            return arr[low][high];
        }
        else if (high > 0 && arr[low][high - 1] < arr[low][high])
        {
            return local_minima(n, arr, low, high - 1);
        }
        else if (high < n - 1 && arr[low][high + 1] < arr[low][high])
        {
            return local_minima(n, arr, low, high + 1);
        }
        else if (low > 0 && arr[low - 1][high] < arr[low][high])
        {
            return local_minima(n, arr, low - 1, high);
        }
        else
        {
            return local_minima(n, arr, low + 1, high);
        }
    }
    printf("Enter the size of the array\n");
    int n;
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = local_minima(n, a, n / 2, n);
    printf("The value of the Local Minima at index  %d is %d (if indexing starts from 1)\n", ans + 1, a[ans][ans]);
}

int main()
{

    while (1)
    {
        printf("C Code Implementation of ADSA HW Assignment-2\n");
        printf("-----------------------------------------------\n\n\n");
        printf("1=> Q(1)\t2=>Q(2a)\t3=>Q(2b)\t4=>Q(3c)\t5=>Q(3f)\t6=>Q(4a(iv))\t7=>Q(4b(iv))\t8=> For Exit\n\n");
        int op;
        printf("Enter your choice number\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            q1();
            break;
        case 2:
            q2a();
            break;
        case 3:
            q2b();
            break;
        case 4:
            q3c();
            break;
        case 5:
            q3f();
            break;
        case 6:
            q4aiv();
            break;
        case 7:
            q4biv();
            break;
        case 8:
            printf("Thanks for Joining. Happy Coding! :)\n");
            exit(0);
            break;

        default:
            printf("Please enter a valid input number\n");
        }
    }
    return 0;
}