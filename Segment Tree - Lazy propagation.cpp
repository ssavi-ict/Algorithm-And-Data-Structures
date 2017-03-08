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
#define ii(a) scanf("%lld", &a)
#define PP(a) printf("%I64d", a)
#define pp(a) printf("%lld", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 100007
#define logbase(a, b) ( log10(a)/log10(b) )

using namespace std;
LL arr[MAX];
struct info{
   LL sum, prop;
};

info tree[MAX*3];

void build(LL node, LL b, LL e)
{
    if(b==e){
        tree[node].sum = arr[b];
        return ;
    }
    LL left = 2*node;
    LL right = 2*node + 1;
    LL mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1,e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

LL query(LL node, LL b, LL e, LL i, LL j, LL carry)
{
    if(i>e || j<b)  return 0;
    if(b>=i && e<=j){
        return tree[node].sum + carry*(e-b+1);
    }
    LL left = 2*node;
    LL right = 2*node + 1;
    LL mid = (b+e)/2;
    LL ret1 = query(left, b, mid, i, j, carry + tree[node].prop);
    LL ret2 = query(right, mid+1, e, i, j, carry + tree[node].prop);

    return ret1 + ret2;
}

void update(LL node, LL b, LL e, LL i, LL j, LL x)
{
    if(i>e || j<b)  return ;
    if(b>=i && e<=j){
        tree[node].sum = tree[node].sum + (e-b+1)*x;
        tree[node].prop = tree[node].prop + x;
        return ;
    }

    LL left = node*2;
    LL right = node*2 + 1;
    LL mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum + ((e-b+1)*tree[node].prop);

}


int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        LL n, q, type, v1, v2, v3;
        ii(n); ii(q);
        ERASE(tree, 0);
        for(int i=1; i<=n; i++) si(arr[i]);
        build((LL)1, (LL)1, n);
        while(q--)
        {
            ii(type); ii(v1); ii(v2);
            if(type==0){
                ii(v3); update(1, 1, n, v1, v2, v3);
            }
            else
              printf("%lld\n", query(1, 1, n, v1, v2, 0));
        }
    }
}

