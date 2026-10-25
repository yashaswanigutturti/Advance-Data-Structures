#include <stdio.h>

int graph[10][10], visited[10], queue[10];
int n;
int front, rear;

void bfs(int start)
{
    int i, node;

    front = rear = -1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while (front != rear)
    {
        node = queue[++front];
        printf("%d ", node);

        for (i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void dfs(int node)
{
    int i;

    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    dfs(start);

    return 0;
}