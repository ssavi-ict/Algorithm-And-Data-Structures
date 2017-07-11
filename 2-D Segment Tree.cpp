#include<bits/stdc++.h>
#define LL long long
#define DBGA(a) cout<<a<<endl


using namespace std;

LL arr[505][505];
LL tree[4*505][4*505];
int n, m;

void build_y(int nx, int lx, int rx, int ny, int ly, int ry)
{
    if(ly==ry){
        if(lx==rx) tree[nx][ny] = arr[lx][ry];
        else tree[nx][ny] = tree[nx*2][ny] + tree[nx*2+1][ny];
        return;
    }
    int my = (ly + ry)>>1;
    build_y(nx, lx, rx, 2*ny, ly, my);
    build_y(nx, lx, rx, 2*ny+1, my+1, ry);
    tree[nx][ny] = tree[nx][2*ny] + tree[nx][2*ny+1];
}

void build_x(int nx, int lx, int rx)
{
    if(lx!=rx){
        int mx = (lx + rx)>>1;
        build_x(nx*2, lx, mx);
        build_x(nx*2+1, mx+1, rx);
    }
    build_y(nx, lx, rx, 1, 0, m-1);
}

LL query_y(int nx, int ny, int ly, int ry, int y1, int y2)
{
    if(ly>y2 || ry<y1) return 0;
    if(y1<=ly && y2>=ry)
        return tree[nx][ny];
    int my = (ly + ry)>>1;
    return query_y(nx, ny*2, ly, my, y1, y2) +
            query_y(nx, ny*2+1, my+1, ry, y1, y2);
}

LL query_x(int nx, int lx, int rx, int x1, int y1, int x2, int y2)
{
    if(rx<x1 || lx>x2) return 0;
    if(x1<=lx && x2>=rx){
        return query_y(nx, 1, 0, m-1, y1, y2);
    }
    int mx = (lx + rx)>>1;
    return query_x(nx*2, lx, mx, x1, y1, x2, y2) +
            query_x(nx*2+1, mx+1, rx, x1, y1, x2, y2);
}

void upd_y(int nx, int lx, int rx, int ny, int ly, int ry, int y, LL val )
{
    if(ly==ry){
        if(lx==rx) tree[nx][ny] = val;
        else tree[nx][ny] = tree[nx*2][ny]+ tree[nx*2+1][ny];
        return;
    }
    int my = (ly + ry)>>1;
    if(y<=my) upd_y(nx, lx, rx, ny*2, ly, my, y, val);
    else upd_y(nx, lx, rx, ny*2+1, my+1, ry, y, val);

    tree[nx][ny] = tree[nx][ny*2]+ tree[nx][ny*2+1];
}

void upd_x(int nx, int lx, int rx, int x, int y, LL val)
{
    if(lx!=rx){
        int mx = (lx + rx)>>1;
        if(x<=mx) upd_x( nx*2, lx, mx, x,  y, val);
        else upd_x(nx*2+1, mx+1, rx, x, y, val);
    }
    upd_y(nx, lx, rx, 1, 0, m-1, y, val);
}

int main()
{

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%lld", &arr[i][j]);
        }
    }
    build_x(1, 0, n-1);
    int q;
    scanf("%d", &q);
    while(q--){
        int op, x1, y1, x2, y2;
        LL val;
        scanf("%d %d %d", &op, &x1, &y1);
        if(op==1){
            scanf("%d %d", &x2, &y2);
            printf("%lld\n", query_x(1, 0, n-1, x1, y1, x2, y2));
        }
        else{
            scanf("%lld", &val);
            upd_x(1, 0, n-1, x1, y1, val);
        }
    }

}
