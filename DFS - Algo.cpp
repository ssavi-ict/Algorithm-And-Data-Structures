#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define PB(a, b) a.push_back(b)
#define PB2(a,i,b) a[i].push_back(b)
#define LL long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define sll(a) scanf("%I64d", &a)
#define pll(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)

using namespace std;

int one ,five, ten, twenty, fifty;

vector<int>graph[10000];
int visited[10003];
int d[10003], f[10003];
int parent[10003];
int ti;

void DFS_Visit(int node)
{
    visited[node] = 1;
    ti = ti + 1;
    d[node] = ti;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(visited[graph[node][i]]==0)
        {
            parent[graph[node][i]] = 1;
            DFS_Visit(graph[node][i]);
        }
        else if(visited[graph[node][i]]==1)
        {
            printf("Got a Cycle\n");
        }
    }

    visited[node] = 2;
    ti = ti + 1;
    f[node] = ti;

    return;
}


void DFS(int node, int edge)
{
    for(int i=1; i<=node; i++)
    {
        visited[i] = 0;
        parent[i] = i;
    }
    ti = 0;
    for(int i=1; i<=node; i++)
    {
        if(visited[i] == 0)
        {
            DFS_Visit(i);
        }
    }
    return;
}

int main()
{
   int node, edge, u, v;
   scanf("%d %d", &node, &edge);
   for(int i=0; i<edge; i++)
   {
       scanf("%d %d", &u, &v);
       graph[u].push_back(v);
       //graph[v].push_back(u);
   }
   DFS(node, edge);

   for(int i=1; i<=node; i++)
   {
        printf("Starting time: %d Finishing time: %d\n", d[i], f[i]);
        printf("Parent of %d: %d\n", i, parent[i]);
   }


}

