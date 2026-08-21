#include <stdio.h>
void tower_recursion(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c \n", a, c);
        return;
    }
    tower_recursion(n - 1, a, c, b);
    printf("Move disk %d from %c to %c \n", n, a, c);
    tower_recursion(n - 1, b, a, c);
    return;
}
int main()
{
    int n;
    printf("Enter the number of disks you want: ");
    scanf("%d", &n);
    tower_recursion(n, 'A', 'B', 'C');
}