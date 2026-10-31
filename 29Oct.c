#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n, W;
    int profit[10];
    int weight[10];
    printf("Enter the number of elments: ");
    scanf("%d", &n);
    printf("Enter the total capacity: ");
    scanf("%d", &W);
    printf("Enter the weight and profit for %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] +
                        dp[i - 1][w - weight[i - 1]],

                    dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("Maximum Profit = %d", dp[n][W]);
    return 0;
}