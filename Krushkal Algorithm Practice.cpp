#include<bits/stdc++.h>

using namespace std;

struct data{
int u, v, w;

 bool operator < (const data& p) const
 {
     return w<p.w;
 }

};

vector<data>graph;
int parent[100];

void init(int n)
{
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int findnode(int n)
{
    (parent[n]!=n)?findnode(parent[n]):parent[n];
}

int MST(int n)
{
    init(n);
    sort(graph.begin(),graph.end());
    int szg = graph.size();

    int cost = 0, cnt=0;
    for(int i=0; i<szg; i++)
    {
        int u = findnode(graph[i].u);
        int v = findnode(graph[i].v);
        if(u==v) cout<<graph[i].u<<' '<<graph[i].v<<" Cycle"<<endl;
        if(u!=v)
        {
            parent[v] = u;
            cnt++;
            cost = cost + graph[i].w;
            if(cnt==n-1) break;
        }
    }
    return cost;
}


int main()
{
    int nodes, edges, u, v, w;
    scanf("%d %d", &nodes, &edges);
    for(int i=1; i<=edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        data var;
        var.u = u; var.v = v; var.w = w;
        graph.push_back(var);
    }

    printf("%d\n",MST(nodes));
    return 0;
}
