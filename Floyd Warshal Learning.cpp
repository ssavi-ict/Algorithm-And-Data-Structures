#include<bits/stdc++.h>
#define INF 999999999

using namespace std;

int matrix[100][100];

int main()
{
    int nodes, edges, x, y, cost;
    scanf("%d %d",&nodes, &edges);
    for(int i=1; i<=nodes; i++)
    {
        for(int j=1; j<=nodes; j++)
        {
            if(i==j) matrix[i][j]=0;
            else matrix[i][j] = INF;
        }
    }
    for(int i=1; i<=edges; i++)
    {
        scanf("%d %d %d",&x, &y, &cost);
        matrix[x][y] = cost; matrix[y][x] = cost;
    }
    for(int k=1; k<=nodes; k++)
    {
        for(int i=1; i<=nodes; i++)
        {
            for(int j=1; j<=nodes; j++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    for(int i=1; i<=nodes; i++)
    {
        for(int j=1; j<=nodes; j++)
        {
            if(matrix[i][j]<INF)
              printf("%d\t",matrix[i][j]);
            else
              printf("INF\t");
        }
        printf("\n");
    }
    int s, d;
    while(scanf("%d %d", &s, &d)==2 && s!=0 && d!=0)
    {
        if(matrix[s][d]<INF)
           printf("%d\n",matrix[s][d]);
    }
    return 0;
}
/*
Enter the no. of nodes in the graph :
3
Enter the adjacency matrix :
0 1 1
0 0 1
0 1 0
Enter The cost matrix is :
0 2 3
0 0 5
0 4 0
path matrix is :]nThe output matrix for the given graph is :
0       1       1
0       1       1
0       1       1
all pair shortest  path matrix is :
The output matrix for the given graph is :
0       2       3
0       0       3
0       2       0

*/
