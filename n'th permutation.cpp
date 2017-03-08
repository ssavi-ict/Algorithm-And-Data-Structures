#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL arr[20];

void fff()
{
    arr[0] = 1;
    for(int i=1; i<=20; i++)
        arr[i] = arr[i-1] * i;
}

LL cool(LL m, LL temp, LL sz)
{
    //cout<<m<<' '<<temp<<endl;
    LL c;
    for(LL i=1; i<=sz; i++)
    {
        if(m*i>=temp) { c = i - 1; break;}
    }
    return c;
}

int main()
{
    fff();
    string str, temp = "";
    LL n, to, test;
    scanf("%lld", &test);
    while(test--)
    {
        cin>>str>>n;
        int sz = str.size();
        sort(str.begin(), str.end());
        temp ="";
        to = n + 1;
        for(LL i=1; i<=sz; i++)
        {
            LL id = cool(arr[sz-i], to, sz);
            to = to - (arr[sz-i]*id);
            temp = temp + str[id];
            str.erase(id,1);
        }
        cout<<temp<<endl;
    }
    return 0;
}

