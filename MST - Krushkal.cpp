#include<bits/stdc++.h>
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define CLR(a) a.clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define PB(a, b) a.push_back(b)
#define LL long long

using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge& p)const
    {
        return w<p.w;
    }
};

vector<edge>graph;
int father[10005];

int parent(int src)
{
    if(src==father[src]) return src;
    else return father[src] = parent(father[src]);
}

void MST(int n)
{
    sort(graph.begin(), graph.end());
    for(int i=0; i<n+5; i++)  father[i] = i;
    int cnt = 0;
    LL cost = 0;
    int sz = SIZE(graph);
    for(int i=0; i<sz; i++)
    {
        int u = parent(graph[i].u);
        int v = parent(graph[i].v);
        if(u!=v)
        {
            father[u] = v;
            cnt++;
            cost = cost + (LL) graph[i].w;
            if(cnt==n-1) break;
        }
    }
    printf("%lld\n", cost);
}

int main()
{
    int n, m, u, v, w;
    while(scanf("%d %d", &n, &m)==2)
    {
        CLR(graph);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge get;
            get.u = u; get.v = v;
            get.w = w;
            PB(graph, get);
        }
        MST(n);
    }
    return 0;
}

