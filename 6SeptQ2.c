#include <stdio.h>
#include <limits.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}
int maxCrossingSum(int a[], int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int i;
    for (i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubarray(int a[], int low, int high)
{
    int mid;
    int leftSum, rightSum, crossSum;
    if (low == high)
        return a[low];

    mid = (low + high) / 2;
    leftSum = maxSubarray(a, low, mid);
    rightSum = maxSubarray(a, mid + 1, high);
    crossSum = maxCrossingSum(a, low, mid, high);
    return max3(leftSum, rightSum, crossSum);
}
int main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int result = maxSubarray(a, 0, n - 1);
    printf("Maximum subarray sum = %d\n", result);
    return 0;
}