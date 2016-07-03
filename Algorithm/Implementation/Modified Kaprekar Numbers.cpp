#include <bits/stdc++.h>
using namespace std ;
#define ll long long
bool check(ll k){
    if(k == 1)  return true ;
    int d = 0 , p = k ;
    while(p)    d++, p/=10;
    ll u = k*k , v = 0 , c = 1 ;
    while(d){
        v = (u%10)*c + v ; c *= 10 ;
        u /= 10 ;
        if(u && v && u+v==k && u*100 > v){
            //cout<<u<<' '<<v<<' '<<k<<' '<<k*k<<endl;
            return true ;
        }
        d--;
    }
    return false ;
}
int main(){
    int p , q ;
    while(cin >> p >> q){
            bool flag = false ;
        for(int i = p ; i <= q ; i++){
            if(check(i)){
                cout<<i<<' ' ;
                flag = true ;
            }
        }
        if(!flag)   cout<<"INVALID RANGE";
        cout<<endl;
    }
}
