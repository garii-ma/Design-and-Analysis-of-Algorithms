#include <stdio.h>
int binary(int arr[100],int beg,int end,int key)
{
    int mid = (beg + end) / 2;
    while (beg <= end)
    {
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            end = mid - 1;
        else
            beg = mid + 1;
        mid = (beg + end) / 2;
    }
    return -1;
}
int main()
{
    int arr[100];
    int n;
    int key;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (int i = 1; i <=n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element you want to find: ");
    scanf("%d", &key);
    int found = binary(arr, arr[0], arr[n - 1],key);
    if (found == -1)
        printf("Element is not found in the given array.\n");
    else
        printf("Element is found at %d position.\n", found);
    return 0;
}