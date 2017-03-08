#include<bits/stdc++.h>

using namespace std;

vector<int>g[100];

void bfs(int n, int src)
{
    queue< int >q;
    int visit[100]={0}, level[100], parent[100];
    memset(level,-1,sizeof(level));
    visit[src]=1;
    level[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!visit[v])
            {
                visit[v]=1;
                level[v]=level[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
        q.pop();
    }
    for(int i=0; i<n; i++)
        printf("%d to %d = %d\n",src, i, level[i]);
}


int main()
{
   int n, e, src;
   cin>>n>>e;
   for(int i=1; i<=e; i++)
   {
       int x, y;
       cin>>x>>y;
       g[x].push_back(y);
       g[y].push_back(x);
   }
   scanf("%d", &src);
   bfs(n,src);
   return 0;
}
