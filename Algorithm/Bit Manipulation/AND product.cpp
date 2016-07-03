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

int main(){
    int T ;
    cin>>T;
    while(T--){
        ll u , v , a , b , ret;
        cin >> a >> b ;
        ret = a ;
        for(int i = 0 ; i <32 ; i++){
            u = setbit(a , i) ;
            v = clearbit(b , i) ;
            if(u >= a && u <= b && v >= a && v <= b){
                ret = clearbit(ret , i) ;
            }
        }
        cout<<ret<<endl;
    }
}
