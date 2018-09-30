#include<bits/stdc++.h>
#define i64 unsigned long long
 
using namespace std;
 
template<typename T>inline T Bigmod(T a, T b, T MOD){
   T x = 1, y = a%MOD;
    while(b > 0) {
        if(b%2 == 1) {
            x = (x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= (T)2;
    }
    return x;
}
 
const int MAXN = 100000;
int status[(MAXN/32)+10];
int primelist[MAXN], primesz;
 
bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}
 
void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    status[1>>5]=SET(status[1>>5],1&31);
    for(int j=4; j<MAXN; j=j+2)
        status[j>>5]=SET(status[j>>5],j&31);
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
 
    primelist[primesz++] = 2;
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0){
            primelist[primesz++] = i;
        }
    }
}
 
i64 ncnt[103][100005];
i64 lcnt[103][100005];
 
void facto(int cs, int n, int type )
{
    if(type==1){
        for(int i=0; i<primesz; i++){
            if(primelist[i]*primelist[i]>n) break;
            while(n%primelist[i]==0){
                n = n / primelist[i];
                ncnt[cs][primelist[i]]++;
            }
        }
        if(n>1){
            ncnt[cs][n]++;
        }
    }
    if(type==2){
        for(int i=0; i<primesz; i++){
            if(primelist[i]*primelist[i]>n) break;
            while(n%primelist[i]==0){
                n = n / primelist[i];
                if(ncnt[cs][primelist[i]]>0) ncnt[cs][primelist[i]]--;
                else lcnt[cs][primelist[i]]++;
            }
        }
        if(n>1){
            if(ncnt[cs][n]>0) ncnt[cs][n]--;
            else lcnt[cs][n]++;
        }
    }
 
}
 
int main()
{
    sieve();
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++){
       i64 n, r, p;
       scanf("%lld %lld %lld", &n, &r, &p);
       if(r>n){
            puts("0"); continue;
       }
       if(r==n){
            puts("1"); continue;
       }
 
       i64 lft = min(r, n-r);
 
       for(int i=n; i>max(r, n-r); i--){
            facto(caseno, i, 1);
       }
       for(int j=1; j<=min(r, n-r); j++){
            facto(caseno, j ,2);
       }
 
       i64 hor = 1, lob = 1;
       for(int i=0; i<primesz; i++){
            //cout<<primelist[i]<<' '<<ncnt[caseno][primelist[i]]<<' '<<lcnt[caseno][primelist[i]]<<endl;
            if(ncnt[caseno][primelist[i]]>0){
                lob = (lob * Bigmod((i64)primelist[i], ncnt[caseno][primelist[i]], p))%p;
            }
            if(lcnt[caseno][primelist[i]]>0){
                hor = (hor * Bigmod((i64)primelist[i], lcnt[caseno][primelist[i]], p))%p;
            }
       }
 
 
       i64 ans = (lob * Bigmod(hor, p-2, p))%p;
       printf("%lld\n", ans);
    }
}
