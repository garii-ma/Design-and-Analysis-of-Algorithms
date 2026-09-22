#include <stdio.h>
#include <limits.h>
#define MAX 100
int main()
{
    int graph[MAX][MAX];
    int selected[MAX];
    int V;
    int i, j;
    int edges = 0;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (i = 0; i < V; i++)
        selected[i] = 0;
    selected[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < V - 1)
    {
        int min = INT_MAX;
        int x = -1;
        int y = -1;
        for (i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < V; j++)
                {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (x == -1)
        {
            printf("MST does not exist.\n");
            return 0;
        }
        printf("%d -- %d  Weight = %d\n",
               x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }
    printf("\nMinimum cost = %d\n", totalCost);
    return 0;
}