#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void initialize()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}
void insert(int key)
{
    int index = key % SIZE;
    int i = 0;
    while (i < SIZE)
    {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            return;
        }
        i++;
    }
    printf("Cannot insert %d. Hash Table is full!\n", key);
}
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d : ", i);

        if (hashTable[i] == -1)
            printf("Empty\n");
        else
            printf("%d\n", hashTable[i]);
    }
}
int main()
{
    int n, key;
    initialize();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}