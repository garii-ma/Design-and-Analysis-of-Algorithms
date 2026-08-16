#include <stdio.h>
int small(int arr[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[index])
            {
                index = j;
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
    }
    return arr[k - 1];
}
int main()
{
    int n, k;
    printf("Enter number of elements  ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the Kth smallest element to find : ");
    scanf("%d", &k);
    printf("The element is %d", small(arr, n, k));
    return 0;
}