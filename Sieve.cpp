#include<bits/stdc++.h>

using namespace std;

bool a[10000002];

int main()
{
    memset(a, true , sizeof a);
    a[1] = false;
    for(int i=2; i<=sqrt(10000002); i++)
    {
        if(a[i])
        {
            for(int j=2*i; j<10000002; j=j+i)
            {
                if(a[j]) a[j] = false;
            }
        }
    }
    for(int i=1; i<50; i++)
    {
        if(a[i])
            printf(" %d",i);
    }
    return 1;
}
