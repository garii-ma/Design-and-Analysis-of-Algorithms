#include <stdio.h>
void bucketSort(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1;
    int bucket[range];
    for (int i = 0; i < range; i++)
        bucket[i] = 0;
    for (int i = 0; i < n; i++)
        bucket[arr[i] - min]++;
    int k = 0;
    for (int i = 0; i < range; i++)
    {
        while (bucket[i] > 0)
        {
            arr[k] = i + min;
            k++;
            bucket[i]--;
        }
    }
}
int main()
{
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bucketSort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}