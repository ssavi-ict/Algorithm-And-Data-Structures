/*#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL dp[900][1000];

LL NCR(int n, int r)
{
    if(r==1) return n;
    else if(n==r) return 1;
    else
    {
        if(dp[n][r]!=-1) return dp[n][r];
        else
        {
            dp[n][r]=NCR(n-1,r) + NCR(n-1,r-1);
            return dp[n][r];
        }
    }
}

int main()
{
    int n, r;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d %d", &n, &r)==2)
    {
        printf("%lld\n",NCR(n,r));
    }
    return 0;
}
*/

#include<bits/stdc++.h>
#define LL long long

using namespace std;
LL MOD = 1000003;
LL fact[1000005];

LL Fermat(LL a, LL b, LL MOD)
{
    LL x = 1;
    LL y = a;
    while(b)
    {
        if(b%2==1)
        {
            x = x * y;
            if(x>MOD)
                x = x % MOD;
        }
        y = y * y;
        if(y>MOD)
            y = y % MOD;
        b = b/2;
    }
    return x;
}

void solve()
{
    fact[0] = fact[1] = 1;
    for(int i=2; i<1000001; i++)
        fact[i] = ((fact[i-1]%MOD)*(i%MOD))%MOD;
}

int main()
{
    solve();
    LL n, r, test;
    scanf("%lld",&test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        scanf("%lld %lld", &n, &r);
        //cout<<fact[n]<<' '<<fact[n-r]<<' '<<fact[r]<<endl;
        LL A = ((fact[r]%MOD)*(fact[n-r]%MOD))%MOD;
        LL res = ((Fermat(A, MOD-2, MOD)%MOD) * (fact[n]%MOD))%MOD;
        printf("Case %d: %lld\n",caseno, res);
    }
    return 0;
}
