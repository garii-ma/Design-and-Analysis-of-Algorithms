#include <stdio.h>
int sum(int a, int r, int n)
{
    int summ = 0;
    for (int i = 1; i <= n; i++)
    {
        summ = summ + a;
        a *= r;
    }
    return summ;
}
int main()
{
    int a, r, n;
    printf("Enter the first term: ");
    scanf("%d", &a);
    printf("Enter the common ratio: ");
    scanf("%d", &r);
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Sum of geometric series: %d.\n", sum(a, r, n));
    return 0;
}