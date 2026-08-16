#include <stdio.h>
void SORT(int arr[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[100];
    int n, k;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the Kth smallest element you want to find: ");
    scanf("%d", &k);
    SORT(arr, n);
    printf("The %dth smallest element is %d.\n", k, arr[k - 1]);
    return 0;
}