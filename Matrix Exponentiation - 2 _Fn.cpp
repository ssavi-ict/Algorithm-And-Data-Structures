/** Jai Shree Ram **/
/** ssavi. ICT-4 CoU **/

#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define sc(a) scanf("%I64d", &a)
#define pr(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define nl puts("")
#define pii pair<int,int>
#define PII pair<LL,LL>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))
#define LOOP(i, b, n) for(i=b; i<=n; i++)

using namespace std;

/** ---------------------------------------------- **/
/** Header And Defintions Ends Here. **/
/** ---------------------------------------------- **/

const double GRS = (1 + sqrt(5))/2;

LL power(int X, int P)
{
    LL ans = 1;
    for(int i=1; i<=P; i++){
        ans = ans * (LL)X;
    }
    return ans;
}

LL ABS(LL A, LL B)
{
    LL ret = A - B;
    if(ret<0) return -ret;
    return ret;
}

LL MOD = 1000000007;

LL bigmod(LL a, LL b){
    LL x = 1, y = a%MOD;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

LL MODINVERSE(LL a){
    return bigmod(a, MOD-2);
}

LL ncrdp[900][1000];
LL NCR(int n, int r)
{
    if(r==1) return n;
    else if(n==r) return 1;
    else
    {
        if(ncrdp[n][r]!=-1) return ncrdp[n][r];
        else
        {
            ncrdp[n][r]=NCR(n-1,r) + NCR(n-1,r-1);
            return ncrdp[n][r];
        }
    }
}

const int MAXN = 200005;
int status[(MAXN/32)+10];
vector<int>primelist;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    status[1>>5]=SET(status[1>>5],1&31);
//    for(int j=4; j<=MAXN; j=j+2)
//        status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAXN; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    primelist.push_back(2);
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0) {
            primelist.push_back(i);
        }
    }
}


/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/


void Make_Identity(LL ANS[][2], int n)
{
    memset(ANS, 0, sizeof ANS);
    for(int i=0; i<n; i++) ANS[i][i] = 1;
}

void Multiply(LL A[][2], LL B[][2], LL C[][2])
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            C[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                C[i][j] = ((C[i][j]%MOD) + (A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
}

void Exponentian(LL Z[][2], LL n, LL ANS[][2])
{
    Make_Identity(ANS, 2);
    LL TEMP[2][2];
    while(n)
    {
        if(n&1)
        {
            Multiply(Z, ANS, TEMP);
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    ANS[i][j] = TEMP[i][j];
        }
        Multiply(Z, Z, TEMP);
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    Z[i][j] = TEMP[i][j];

        n = n / 2;
    }
}

LL Mat_Expo(LL a, LL b, LL n)
{
    LL fib;
    if(n>2)
    {
        LL Z[2][2], ANS[2][2];
        memset(ANS, 0, sizeof ANS);

        Z[0][0] = 1;
        Z[0][1] = 1;
        Z[1][0] = 1;
        Z[1][1] = 0;

        Exponentian(Z, n-2, ANS);
        fib = ((ANS[0][0]*b) + ANS[0][1]*a)%MOD;
    }
    else fib = n-1;

    return fib;
}

int main()
{
    long long a, b, n;
    while(scanf("%lld %lld %lld", &a, &b, &n)==3)
    {
        LL ans = Mat_Expo(a,b,n)%MOD;
        printf("%lld\n", ans);
    }
}
