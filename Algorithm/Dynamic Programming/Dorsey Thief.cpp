#include <bits/stdc++.h>
using namespace std ;
#define ll long long
ll n , x ;
vector <ll> w[5005] ;
ll dp[5005][5005] ;
int flag ;
ll f(ll pos , ll g){
    if(g == 0){
        flag = 1 ;
        return 0 ;
    }
    if(pos > x || g < 0)  return -1e9 ;
    if(dp[pos][g] != -1 )return dp[pos][g] ;
    ll ret = f(pos + 1 , g) , u = 0 ;
    for(int i = 0 ; i < w[pos].size() ; i++){
        if( g - (i + 1)*pos < 0 ) break ;
        u += w[pos][i] ;
        ret = max(ret , u + f(pos + 1 , g - (i + 1)*pos)) ;
    }
    return dp[pos][g] = ret ;
}

int main(){
    ll a , b ;
    cin >> n >> x ;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b ;
        if(b <= x){
            w[b].push_back(a) ;
        }
    }
    for(int i = 1 ; i <= x ; i++){
        sort(w[i].begin() , w[i].end() , greater<int>()) ;
    }
    memset(dp , -1 , sizeof(dp)) ;
    f(0 , x) ;
    if(!flag)    cout << "Got caught!\n" ;
    else    cout << f(0 , x) << endl ;
}
