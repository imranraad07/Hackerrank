#include <bits/stdc++.h>
using namespace std ;
#define MOD 1000000007
#define ll long long

ll arr[1000005] ;
ll dp[2][1000005] ;

int main(){
//    freopen("input.txt" , "r" , stdin) ;
    string s ;
    string s1 ; s1.clear() ;
    cin >> s ;
    int sz = s.size() , k = 1 ;
    s1 += s[0] ;
    for(int i = 1 ; i < sz ; i++){
        arr[k]++ ;
        if(s[i] != s[i-1]){
            s1 += s[i] ;
            k++ ;
        }
    }
    for(int i = 0 ; i < k ; i++){
        dp[0][i+1] += dp[0][i] + 1 ;
        dp[1][i+1] += dp[1][i] + dp[0][i] ;
        if(arr[i+1] > 1)  dp[1][i+1]++ ;
        else{
            if(s1[i-1] == s1[i+1]){
                dp[1][i+2]-- ;
            }
        }
    }
    cout << dp[1][k] << endl ;
}
