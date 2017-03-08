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
#define SF(a) scanf("%I64d", &a)
#define PF(a) printf("%I64d\n", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d\n", a)
#define pii pair<int,int>
#define PIS pair<double,string>
#define PII pair<LL,LL>
//#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))
#define LOOP(i, b, n) for(int i=b; i<=n; i++)
#define nl puts("")
#define popcount __builtin_popcount

using namespace std;


#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032

unsigned base[MAX/64], segment[RNG/64], primes[LEN];

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve()
{
    unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    for(i=3, j=0; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++] = i;
//    for(int i=0; i<j; i++){
//        printf("%d ", primes[i]);
//    }
//    puts("");
}

/* Returns the prime-count within range [a,b] and marks them in segment[] */
void segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return ;
    if(a<3){
        printf("2\n");
        a = 3;
    }
    if(a%2==0) a++;
    //cout<<a<<' '<<cnt<<endl;
    mset(segment,0);
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] ); // Ceiling Kora
        if(j%2==0){
            j += primes[i];  // Bejor Korsi Cz Jor diye Kono Kaj Nai
        }

        for(k=primes[i]<<1; j<=b; j+=k){
            if(j!=primes[i]){
                setC(segment, (j-a)); // Deleted the ODD multiple of prime[i].
            }
        }
    }

    int x = a;
    for(i=0; i<=b-a; i+=2){
        if(!chkC(segment, i)){
            printf("%d\n", x+i);
        }
    }
}

int main()
{
    sieve();
    int test;
    scanf("%d", &test);
    bool sp = false;
    while(test--){
        int a, b;
        if(sp) puts("");
        sp = true;
        scanf("%d %d", &a, &b);
        segmented_sieve(a, b);
    }
}
