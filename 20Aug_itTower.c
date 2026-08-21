#include <stdio.h>
struct stack
{
    int n;
    char source;
    char auxiliary;
    char destination;
};
int main()
{
    int n;
    printf("Enter the number of disks you want: ");
    scanf("%d", &n);
    struct stack ss[100];
    int top = -1;
    top++;
    ss[top].n = n;
    ss[top].source = 'A';
    ss[top].auxiliary = 'B';
    ss[top].destination = 'C';
    while (top != -1)
    {
        struct stack cur = ss[top];
        top--;
        if (cur.n < 0)
        {
            printf("Move disk %d from %c to %c.\n", -cur.n, cur.source, cur.destination);
        }
        else if (cur.n == 1)
        {
            printf("Move disk 1 from %c to %c.\n", cur.source, cur.destination);
        }
        else
        {
            top++;
            ss[top].n = cur.n - 1;
            ss[top].source = cur.auxiliary;
            ss[top].auxiliary = cur.source;
            ss[top].destination = cur.destination;
            top++;
            ss[top].n = -cur.n;
            ss[top].source = cur.source;
            ss[top].auxiliary = cur.auxiliary;
            ss[top].destination = cur.destination;
            top++;
            ss[top].n = cur.n - 1;
            ss[top].source = cur.source;
            ss[top].auxiliary = cur.destination;
            ss[top].destination = cur.auxiliary;
        }
    }
    return 0;
}