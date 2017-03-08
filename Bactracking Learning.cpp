#include<bits/stdc++.h>

using namespace std;
char arr[] = {'a', 'b', 'c', 'd'};
vector<char>result;
int taken[20]={0};

void call()
{
    if(result.size()==3)
    {
        for(int i=0; i<3; i++)
            printf("%c",result[i]);
        puts(" ");
        return;
    }
    for(int i=0; i<4; i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1;
            result.push_back(arr[i]);
            call();
            taken[i]=0;
            result.pop_back();
        }
    }
}

int main()
{
    call();
    return 0;
}
/*
Output For Array :
abcd
abdc
acbd
acdb
adbc
adcb
bacd
badc
bcad
bcda
bdac
bdca
cabd
cadb
cbad
cbda
cdab
cdba
dabc
dacb
dbac
dbca
dcab
dcba
*/

