#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005] ;
ll b[200005] ;
ll c[200005] ;
bool vis[200005] ;
vector<int>v ;
int main(){
    int n ; ll c1 ;
    scanf("%d %lld" , &n , &c1) ;
    for(auto i = 1 ; i <= n ; i++){
        scanf("%lld" , &a[i]) ;
        a[i] = min(a[i] , c1) ;
    }
    for(auto i = 1 ; i <= n ; i++){
        scanf("%lld" , &b[i]) ;
    }
    for(auto i = 1 ; i <= n ; i++){
        c[i] = a[i] - b[i] ;
        c[i + n] = c[i] ;
    }
    for(int i = 2*n ; i >= 1 ; i--){
        if(vis[i%n])    continue ;
        if(c[i] < 0){
            int cur = i ;
            ll d = -c[cur--] ;
            while(cur >= 1 && d >= 0){
                vis[cur%n] = true ;
                d -= c[cur--] ;
                d = min(d , c1) ;
            }
        }
    }
    int ret = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]) ret++ ;
    }
    cout << ret << endl ;
}
