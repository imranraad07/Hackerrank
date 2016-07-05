#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll x , v , x2 , v2 ;
    cin >> x >> v ;
    cin >> x2 >> v2 ;

    if(v == v2 || x == x2){
        if(x == x2) cout << "YES\n" ;
        else    cout <<"NO\n" ;
        return 0 ;
    }

    ll u = x2 - x ;
    v = v2 - v ;
    if(u < 0){
        u = -u ;
        v = -v ;
    }
    if(u % v == 0 && u*v < 0 ) cout << "YES\n" ;
    else    cout << "NO\n" ;
}
