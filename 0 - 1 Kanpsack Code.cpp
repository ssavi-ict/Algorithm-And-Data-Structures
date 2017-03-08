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
#define ULL unsigned long long
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
#define MAX 100006
#define CASE(i) printf("Case %d: ", i);
#define CSH(i) printf("Case #%d: ", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)


LL MOD = 1000000007;

using namespace std;

LL bigmod(LL b, LL p, LL m)
{
    if(p==0)  return 1;
    if(p%2==0)
    {
        LL x = bigmod(b,p/2,m);
        return (x%m * x%m)%m;
    }
    else return ((b%m)*bigmod(b,p-1,m)%m)%m;
}


LL MODINVERSE(LL a)
{
    return bigmod(a, MOD-2, MOD);
}

int N, CAP;
int arr[100], cost[100];
int dp[100][10000];

int solve(int i, int wt)
{
    if(i==N+1) return 0;
    if(dp[i][wt]!=-1)  return dp[i][wt];
    int cost1 = 0, cost2 = 0;
    if(wt + arr[i]<=CAP)
        cost1 = cost[i] + solve(i+1, wt + arr[i]);
    cost2 = solve(i+1, wt);
   // cout<<cost1<<' '<<cost2<<endl;
    dp[i][wt] = max(cost1, cost2);
    return dp[i][wt];
}

int main()
{
    scanf("%d %d", &N, &CAP);
    for(int i=1; i<=N; i++){
        scanf("%d %d", &arr[i], &cost[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("Maximal Cost: %d\n", solve(1,0));
}

/// KnapSack Item Printing Code: http://pastebin.ubuntu.com/22396978/ ///
/// KnapSack Item Printing Code: http://pastebin.ubuntu.com/22418770/ ///
