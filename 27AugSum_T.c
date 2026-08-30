#include <stdio.h>
#define SIZE 1000
int hashTable[SIZE];
int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}
int main()
{
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter target value: ");
    scanf("%d", &target);
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int required = target - arr[i];
        int requiredIndex = hashFunction(required);
        int index = requiredIndex;
        while (hashTable[index] != 0)
        {
            if (hashTable[index] == required)
            {
                printf("Two elements found: %d and %d\n",
                       arr[i], required);
                return 0;
            }
            index = (index + 1) % SIZE;
            if (index == requiredIndex)
                break;
        }
        int insertIndex = hashFunction(arr[i]);
        while (hashTable[insertIndex] != 0)
        {
            insertIndex = (insertIndex + 1) % SIZE;
        }
        hashTable[insertIndex] = arr[i];
    }
    printf("No two elements have sum equal to %d\n", target);
    return 0;
}