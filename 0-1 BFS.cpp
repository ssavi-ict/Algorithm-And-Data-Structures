#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
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
#define II(a) scanf("%I64d", &a)
#define PP(a) printf("%I64d", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define pii2 pair<int, pii>
#define MAX 1000
#define MAXN 100007
#define logbase(a, b) ( log10(a)/log10(b) )
#define DIR(f,s,R,C) (f>=0 && f<R && s>=0 && s<C)
#define DIR1(f,s,R,C) (f>=1 && f<=R && s>=1 && s<=C)
#define CASE(i) printf("Case %d:", i);


using namespace std;

int level[1005][1005];
char grid[1005][1005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m, n;

int BFS()
{
    int ans = 0;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) level[i][j] = INT_MAX;
    deque<pii>q;
    q.push_front(pii(0,0));
    level[0][0] = 1;

    while(!q.empty())
    {
        pii top = q.front();

        q.pop_front();
        if(top.first==m-1 && top.second==n-1) break;

        for(int i=0; i<4; i++)
        {
            int u = top.first + dx[i];
            int v = top.second + dy[i];

            if(u>=0 && v>=0 && u<m && v<n)
            {
             //   cout<<endl<<u<<' '<<v<<' '<<top.first<<' '<<top.second;
                if(grid[u][v]==grid[top.first][top.second] && level[u][v]>level[top.first][top.second])
                {

                    level[u][v] = level[top.first][top.second];
                    q.push_front(pii(u,v));
                }
                else if(level[u][v]>level[top.first][top.second]+1)
                {
                    level[u][v] = level[top.first][top.second] + 1;
                    q.push_back(pii(u,v));
                }
            }
        }
    }
    ans = level[m-1][n-1] - 1;

    return ans;
}

int main()
{
    int test;
    scanf("%d", &test);A
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d %d", &m, &n);
        for(int i=0; i<m; i++)
        {
            scanf("%s", grid[i]);
        }
       // CASE(caseno);
       // printf(" ");
        printf("%d\n", BFS());
    }
}

