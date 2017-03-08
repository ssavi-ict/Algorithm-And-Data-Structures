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
#define MAX 600005
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define piis pair<int, string>

using namespace std;

int failed[1000007];

void failure_function(char *pattern)
{
    int len = strlen(pattern);
    int i=0, j=-1;
    failed[i] = j;
    while (i<len)
    {
        while (j>=0 && pattern[i]!=pattern[j]) j = failed[j];
        i++; j++;
        failed[i] = j;
    }
    for(int j=0; j<len; j++) cout<<failed[j]<<' ';

    cout<<endl;
}

void KMP(char *str, char *pattern)
{
    int len = strlen(str);
    int sz = strlen(pattern);
    int i = 0, j = 0, cnt = 0;

    while(i<len)
    {
        while (j>=0 && str[i]!=pattern[j]) j = failed[j];
        i++; j++;
        if(j==sz)
        {
            j = failed[j];
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return;
}

int main()
{
    int test;
    scanf("%d", &test);
    getchar();
    for(int caseno=1; caseno<=test; caseno++)
    {
        char str[1000007], pat[1000007], c;
        int i;
        scanf("%s\n%s", str, pat);

        failure_function(pat);
        //KMP(str, pat);
    }
}

//http://pastebin.ubuntu.com/17097834/

