#include<bits/stdc++.h>

using namespace std;


int findParent(int i,int parent[])
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i],parent);
    return parent[i];
}
void unionNodes(int a,int b,int parent[],int size[])
{
    int parent_a=findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}

int main()
{

    int N,M,i,a,b;
    scanf(" %d %d",&N,&M);
    int parent[100001]={0},size[100001]={0};
    for(i=1;i<=N;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    for(i=1;i<=M;i++)
    {
        scanf(" %d %d",&a,&b);
        unionNodes(a,b,parent,size);
    }

    for(i=1;i<=N;i++)
        printf("Node %d belongs to connected component %d\n",i,findParent(i,parent));
    long long ways=1;
    int nos=0;
    for(i=1;i<=N;i++)
    {
        if(findParent(i,parent)==i)
        {
            printf("%d leader %d size\n",i,size[i]);
            nos++;
        }

    }
    printf("Total connected components : %d",nos);

    return 0;
}

/*int nodes[10];
int rankof[10];

int findnode(int a, int nodes[])
{
    if(nodes[nodes[a]]!=nodes[a])
        nodes[a] = findnode(nodes[a], nodes);
    return nodes[a];
}
void makeunion(int a, int b, int nodes[], int rankof[])
{
    int u = findnode(a, nodes);
    int v = findnode(b, nodes);
    //cout<<"GOT="<<u<<' '<<v<<endl;
    if(u==v) return;
    if(rankof[u]>=rankof[v])
    {
        rankof[u] = rankof[u] + rankof[v];
        nodes[v] = u;
    }
    else
    {
        rankof[v] = rankof[v] + rankof[u];
        nodes[u] = v;
    }
    return;
}

int main()
{
    //init();
    int x, y;
    memset(nodes,0,sizeof(nodes));
    memset(rankof,0,sizeof(rankof));
    for(int i=1; i<=10; i++)
        { nodes[i] = i; rankof[i] = 1; }
    for(int i=1; i<=7; i++)
    {
        scanf("%d %d", &x, &y);
        makeunion(x,y, nodes, rankof);
    }
    for(int i=1; i<10; i++)
        cout<<findnode(i, nodes)<<endl;
    return 0;
}*/
/*2 4
2 3
2 1
3 6
6 7
4 5
8 9

#include<bits/stdc++.h>

using namespace std;

int nodes[10];
int rankof[10];

void init()
{
    for(int i=1; i<=10; i++)
        { nodes[i] = i; rankof[i] = 1; }
}

int findnode(int a, int nodes[])
{
    if(nodes[nodes[a]]!=nodes[a])
        nodes[a] = findnode(nodes[a], nodes);
    return nodes[a];
}
void makeunion(int a, int b, int nodes[], int rankof[])
{
    int u = findnode(a, nodes);
    int v = findnode(b, nodes);
    //cout<<"GOT="<<u<<' '<<v<<endl;
    if(u==v) return;
    if(rankof[u]>=rankof[v])
    {
        rankof[u] = rankof[u] + rankof[v];
        nodes[v] = u;
    }
    else
    {
        rankof[v] = rankof[v] + rankof[u];
        nodes[u] = v;
    }
    return;
}

int main()
{
    init();
    int x, y;
    for(int i=1; i<=7; i++)
    {
        scanf("%d %d", &x, &y);
        makeunion(x,y, nodes, rankof);
    }
    for(int i=1; i<10; i++)
        cout<<findnode(i, nodes)<<endl;
    return 0;
}
*/
