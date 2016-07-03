#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr1[102] ;
int arr2[102] ;
int dp[102][102] ;

int main() {
    int n , m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++)    cin >> arr1[i];
    for(int i = 1 ; i <= m ; i++)    cin >> arr2[i];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(arr1[i] == arr2[j])  dp[i][j] = 1 + dp[i-1][j-1] ;
            else    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
        }
    }
    vector<int>v(dp[n][m]) ;
    int i = n , j = m , sz = dp[n][m];
    while(i > 0 && j > 0 && sz >= 0){
        if(arr1[i] == arr2[j]){
            v[sz-1] = arr1[i] ;
            i--;
            j--;
            sz--;
        }
        else if(dp[i-1][j] > dp[i][j-1])    i--;
        else    j--;
    }
    for(int i = 0 ; i < dp[n][m] ; i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}
