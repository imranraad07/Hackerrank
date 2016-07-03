#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll setbit(ll n , int x){
    n |= (1 << x) ;
    return n ;
}
ll clearbit(ll n , int x){
    n &= ~(1 << x);
    return n ;
}
ll togglebit(ll n , int x){
    n ^= 1 << x;
    return n ;
}
ll checkbit(ll n , int x){
    return ((n) & (1<<(x))) ;
}

int arr[105] ;

int main(){
    int j , n , i ;
    cin >> n ;
    for(i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    sort(arr , arr+n) ;
    for(i = 31 ; i >= 0 ; i--){
        if(checkbit(arr[n-1] , i))  break ;
    }
    int v , c = 0 , k , u ;
    for( i-- ; i >= 0 ; i--){
        c = 0 ;
        for(j = 0 ; j < n ; j++){
            v = arr[j]/(1<<i) ;
            u = 0 ;
            for(k = 0 ; k < n ; k++){
                if(arr[k]/(1<<i) == v)  u++ ;
            }
            c = max(c , u) ;
        }
        if((c<<1) <= n){
            cout<<i<<endl;
            return 0 ;
        }
    }
    cout<<-1<<endl;
}
