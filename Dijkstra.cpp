#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

vector<int>graph[MAX], cost[MAX];

struct node
{
    int u, w;
    node(int a, int b) { u = a; w = b; }
    bool operator <(const node& p) const { return w>p.w; }
};

long long int d[MAX];
int par[MAX];

long long int dijkstra(int n)
{
    for(int i=0; i<=MAX; i++)
    {
        d[i] = LLONG_MAX;
        par[i] = -1;
    }
    priority_queue<node>pq;
    pq.push(node(1, 0));
    d[1] = 0;
    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        int u = top.u;
        if(u==n) return d[n];
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(d[v]>d[u]+cost[u][i])
            {
                d[v] = d[u] + cost[u][i];
                pq.push(node(v,d[v]));
                par[v] = u;
            }
        }
    }
    return -1;
}

int main()
{
    int n, e, u, v, w;
    scanf("%d %d", &n, &e);
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    long long int res = dijkstra(n);
    cout<<res<<endl;

    if(res==-1) printf("NO WAY");
    else
    {
        vector<int>output;
        int p = n;
        while(p!=-1)
        {
            output.push_back(p);
            p = par[p];
        }
        reverse(output.begin(), output.end());
        for(int i=0; i<output.size(); i++) cout<<output[i]<< ' ';
    }
    return 0;
}
