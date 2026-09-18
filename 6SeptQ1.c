#include <stdio.h>
struct MinMax
{
    int min;
    int max;
};
struct MinMax findMinMax(int a[], int low, int high)
{
    struct MinMax result, left, right;
    int mid;
    if (low == high)
    {
        result.min = a[low];
        result.max = a[low];
        return result;
    }
    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            result.min = a[low];
            result.max = a[high];
        }
        else
        {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }
    mid = (low + high) / 2;
    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}
int main()
{
    int a[] = {7, 2, 9, 4, 1, 8, 5};
    int n = sizeof(a) / sizeof(a[0]);
    struct MinMax result;
    result = findMinMax(a, 0, n - 1);
    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);
    return 0;
}