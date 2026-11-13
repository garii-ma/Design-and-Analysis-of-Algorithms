#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int board[MAX];
int count = 0;
int isSafe(int row, int col)
{
    int i;
    for (i = 0; i < row; i++)
    {
        if (board[i] == col)
            return 0;
        if (abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}
void printBoard(int n)
{
    int i, j;
    count++;
    printf("\nSolution %d:\n", count);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
void solveNQueen(int n, int row)
{
    int col;
    if (row == n)
    {
        printBoard(n);
        return;
    }
    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            solveNQueen(n, row + 1);
            board[row] = -1;
        }
    }
}
int main()
{
    int n, i;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
    {
        printf("Invalid value of N.\n");
        return 1;
    }
    for (i = 0; i < n; i++)
        board[i] = -1;
    solveNQueen(n, 0);
    if (count == 0)
        printf("\nSolution does not exist.\n");
    else
        printf("\nTotal solutions = %d\n", count);
    return 0;
}