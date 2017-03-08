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

LL power(int X, int P)
{
    LL ans = 1;
    for(int i=1; i<=P; i++){
        ans = ans * (LL)X;
    }
    return ans;
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

const int MAXN = 46400;
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


/**-------------------------------------------------------------------**/
/** Template Ends Here. Main Function Starts Here. **/
/**------------------------------------------------------------------**/

int caseno;
char str[1005], ttr[1005];
int visited[1005][1005], len1, len2;
LL lcslen;
LL dp[1005][1005];
string ans, res;

LL LCS(int pos1, int pos2)
{
    if(pos1==len1 || pos2==len2)  return 0;
    if(visited[pos1][pos2]==caseno)  return dp[pos1][pos2];
    visited[pos1][pos2] = caseno;

    LL ans = 0;
    if(str[pos1]==ttr[pos2]){
        ans = 1 + LCS(pos1+1, pos2+1);
    }
    else{
        ans = max(LCS(pos1, pos2+1), LCS(pos1+1, pos2));
    }
    dp[pos1][pos2] = ans;
    return dp[pos1][pos2];
}

void LCSPRINT(int pos1, int pos2)
{
    if(pos1==len1 || pos2==len2){
        cout<<ans;
        return;
    }
    if(str[pos1]==ttr[pos2]){
        ans = ans + str[pos1];
        LCSPRINT(pos1+1, pos2+1);
    }
    else{
        if(dp[pos1+1][pos2]>dp[pos1][pos2+1]) LCSPRINT(pos1+1, pos2);
        else LCSPRINT(pos1, pos2+1);
    }
}

void LCSPRINTALL(int pos1, int pos2)
{
    if(pos1==len1 || pos2==len2){
        cout<<res;
        puts("");
        return;
    }
    if(str[pos1]==ttr[pos2]){
        res = res + str[pos1];
        LCSPRINTALL(pos1+1, pos2+1);
        res.erase(res.end()-1);
    }
    else{
        if(dp[pos1+1][pos2]>dp[pos1][pos2+1]) LCSPRINTALL(pos1+1, pos2);
        else if(dp[pos1+1][pos2]<dp[pos1][pos2+1]) LCSPRINTALL(pos1, pos2+1);
        else{
            LCSPRINTALL(pos1+1, pos2);
            LCSPRINTALL(pos1, pos2+1);
        }
    }
}



int main()
{
    int test;
    scanf("%d", &test);
    getchar();
    LOOP(caseno, 1, test)
    {
        ans.clear(); res.clear();
        scanf("%s", str); len1 = strlen(str);
        scanf("%s", ttr); len2 = strlen(ttr);
        lcslen = LCS(0, 0);
        printf("LCS Length: %lld\n", lcslen);
        printf("LCS is:\n");
        LCSPRINT(0, 0); puts("");
        printf("All LCS ARE:\n");
        LCSPRINTALL(0, 0);
    }
}

