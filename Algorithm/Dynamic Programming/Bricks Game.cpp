#include <bits/stdc++.h>
using namespace std ;
#define ll long long
ll arr[100005] ;
ll dp[100005] ;

int main(){
    int T ;
    cin >> T ;
    while(T--){
        memset(dp , 0 , sizeof(dp)) ;
        memset(arr , 0 , sizeof(dp)) ;
        int n ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i] ;
        }
        if(n <= 3){
            cout << arr[0] + arr[1] + arr[2] << endl;
            continue ;
        }
        ll s = 0 ;
        for(int i = n-1 ; i >= 0 ; i--){
            s += arr[i] ;
            dp[i] = s - min(dp[i+3] , min(dp[i+1] , dp[i+2])) ;
        }
        cout << dp[0] << endl;
    }
}
