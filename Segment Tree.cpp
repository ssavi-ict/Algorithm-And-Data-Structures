#include<bits/stdc++.h>
#define LL long long

using namespace std;

int arr[100005];
int tree[3*100005];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(j<b || i>e) return 0;
    if(b>=i && e<=j) return tree[node];
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    int seg1 = query(left, b, mid, i, j);
    int seg2 = query(right, mid+1, e, i, j);
    return seg1 + seg2;
}

void update(int node, int b, int e, int i, int value)
{
    if(i>e || i<b) return;
    if(b>=i && e<=i){
        tree[node] = value;
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, value);
    update(right, mid+1, e, i, value);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", arr+ i);
    init(1,1,n);
    int q, b, e;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        scanf("%d %d", &b, &e);
        printf("%d\n", query(1, 1, n, b, e));
    }
    int up, node, value;
    scanf("%d", &up);
    for(int i=0; i<up; i++)
    {
        scanf("%d %d", &node, &value);
        update(1, 1, n, node, value);
        scanf("%d %d", &b, &e);
        printf("%d\n", query(1, 1, n, b, e));
    }
    return 0;
}
