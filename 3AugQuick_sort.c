#include <stdio.h>
#include <stdlib.h>
int partition(int arr[100], int low, int high)
{
    int i = low;
    int j = high - 1;
    int p = arr[low];
    while (i < j)
    {
        while (i < j && arr[j] > p)
            j--;
        while (i < j && arr[i] <= p)
            i++;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = p;
    return j;
}
void quicksort(int arr[100], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot);
        quicksort(arr, pivot + 1, high);
    }
}
int main()
{
    int arr[100];
    int n;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}