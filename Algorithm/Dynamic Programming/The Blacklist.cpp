#include <bits/stdc++.h>
using namespace std ;
int a[21][21] , n , m ;
int dp[21][(1<<12)] ;
bool check(int mask,int k){
    return (mask)&(1<<k) ;
}
int set1(int mask,int k){
    return (mask)|(1<<k) ;
}
int f(int i , int mask){
    if(i == n) return 0 ;
    if(mask == (1<<m) - 1)  return 1e9 ;
    if(dp[i][mask] != -1)   return dp[i][mask] ;
    int ret = 1e9 , j ;
    for(int j = 0 ; j < m ; j++){
        if(check(mask , j))   continue ;
        int u = 0 ;
        for(int k = i ; k < n ; k++){
            u += a[j][k] ;
            ret = min(ret , u + f(k + 1 , set1(mask , j))) ;
        }
    }
    return dp[i][mask]=ret;
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j] ;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << f(0 , 0) << endl ;
}
