#include <stdio.h>
#define SIZE 100
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int frequency[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        frequency[i] = 0;
    }
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        frequency[arr[i]]++;
    }
    printf("\nFrequency of distinct elements:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%d occurs %d time(s)\n", i, frequency[i]);
        }
    }
    return 0;
}