#include <bits/stdc++.h>
using namespace std;

int n , m ;
int arr[15][15] ;
int ret ;
int vis[15][15] ;

void f(int x , int y , int c){
    if(x > n || y > m || x < 1 || y < 1 || vis[x][y] || (arr[x][y]==0) )  return;
    ret = max(ret,c);
    vis[x][y] = true ;
    f(x+1,y+1,c+1);
    f(x+1,y,c+1);
    f(x+1,y-1,c+1);
    f(x,y+1,c+1);
    f(x,y-1,c+1);
    f(x-1,y+1,c+1);
    f(x-1,y,c+1);
    f(x-1,y-1,c+1);
    vis[x][y] = false ;
}

int main() {
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> arr[i][j] ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            f(i,j,arr[i][j]);
            memset(vis,0,sizeof(vis));
        }
    }
    cout<<ret<<endl;
    return 0;
}

