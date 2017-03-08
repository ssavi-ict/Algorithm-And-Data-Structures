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
#define CASE(i) printf("Case %d:\n", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)

using namespace std;

const int mx = 1e7;

int divs[mx+5];
bool chk[mx+5];
int anti[mx+5];

void gen(void)
{
    int i,j,maxi;
    for(i=1; i<=mx; i++)
    {
        for(j=i; j<=mx; j+=i) divs[j]++;
    }
    maxi=0;
    for(i=1; i<=mx; i++)
    {
        if(divs[i]>maxi)
        {
            maxi=divs[i];
            chk[i]=1;
        }
    }
    maxi=10810800;
    for(i=mx; i>0; i--)
    {
        if(chk[i]) maxi=i;
        anti[i]=maxi;
    }
    return;
}

int main()
{
    int q,a;
    gen();
    int k;
    scanf("%d", &k);
    while(k--)
    {
        int n;
        cin>>n;
        printf("%d\n", divs[n]);
    }
    return 0;
}

