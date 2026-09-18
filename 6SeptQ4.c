#include <stdio.h>
struct Item
{
    int value;
    int weight;
    float ratio;
};
void sortItems(struct Item items[], int n)
{
    int i, j;
    struct Item temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
float fractionalKnapsack(struct Item items[], int n, int capacity)
{
    int i;
    float totalValue = 0.0;
    for (i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }
    return totalValue;
}
int main()
{
    struct Item items[] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}};
    int n = 3;
    int capacity = 50;
    int i;
    for (i = 0; i < n; i++)
    {
        items[i].ratio =
            (float)items[i].value / items[i].weight;
    }
    sortItems(items, n);
    printf("Items after sorting by value/weight ratio:\n");
    for (i = 0; i < n; i++)
    {
        printf("Value = %d, Weight = %d, Ratio = %.2f\n",
               items[i].value,
               items[i].weight,
               items[i].ratio);
    }
    printf("\nMaximum value = %.2f\n",
           fractionalKnapsack(items, n, capacity));
    return 0;
}