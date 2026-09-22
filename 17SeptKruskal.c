#include <stdio.h>
#define MAX 100
struct Edge
{
    int src;
    int dest;
    int weight;
};
int parent[MAX];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSets(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    parent[rootV] = rootU;
}
void sortEdges(struct Edge edges[], int e)
{
    int i, j;
    struct Edge temp;
    for (i = 0; i < e - 1; i++)
    {
        for (j = i + 1; j < e; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}
int main()
{
    int V, E;
    int i, count = 0;
    int totalCost = 0;
    struct Edge edges[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }
    for (i = 0; i < V; i++)
        parent[i] = i;
    sortEdges(edges, E);
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        if (find(u) != find(v))
        {
            printf("%d -- %d  Weight = %d\n",
                   u, v, edges[i].weight);
            totalCost += edges[i].weight;
            unionSets(u, v);
            count++;
        }
    }
    if (count != V - 1)
    {
        printf("\nMST does not exist.\n");
    }
    else
    {
        printf("\nMinimum cost = %d\n", totalCost);
    }
    return 0;
}