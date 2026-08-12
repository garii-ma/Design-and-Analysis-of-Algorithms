#include <stdio.h>
int linear(int arr[100],int n, int key)
{
    int position = -1;
    for (int j = 1; j <=n ; j++)
    {
        if (key == arr[j])
            position = j;
    }
    return position;
}
int main()
{
    int arr[100];
    int n;
    int key;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (int i = 1; i <=n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element you want to find: ");
    scanf("%d", &key);
    int found = linear(arr, n, key);
    if (found == -1)
        printf("Element is not found in the given array.\n");
    else
        printf("Element is found at %d position.\n", found);
    return 0;
}