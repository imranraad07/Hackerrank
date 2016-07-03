#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define MaxValue 1000005
ll t[MaxValue+5] ;
ll get(int idx){
    ll ret = -1e18 ;
    while(idx){
        ret = max(ret , t[idx]) ;
        idx -= (idx&(-idx)) ;
    }
    return ret ;
}
void add( int idx , ll val){
    while(idx <= MaxValue){
        t[idx] = max(t[idx] , val) ;
        idx += (idx&(-idx)) ;
    }
}

ll v[MaxValue] ;
int p[MaxValue] ;

int main(){
    fill(t , t + sizeof(t)/sizeof(ll) , (ll)-1e18) ;
    int n ;
    ll sum = 0 ;
    scanf("%d" , &n) ;
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld %lld" , &v[i] , &p[i]) ;
        sum += v[i] ;
    }
    sum -= v[n] ;
    add(n , v[n]) ;
    for(int i = n - 1 ; i > 1 ; i--){
        add(i , get(i + p[i]) - v[i]) ;
    }
    printf("%lld\n", max(v[1] , sum + get(1 + p[1]) - v[1] ) ) ;
}
