#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll check(ll n, ll k){
    ll u = n%k , v = n/k , z = k-u ;
    return u*(v+1)*z*v +
           u*(u-1)*(v+1)*(v+1)/2LL +
           z*(z-1)*v*v/2LL ;
}

int main(){
    int T ;
    cin >> T ;
    while (T--){
        ll n , m ;
        cin >> n >> m ;
        ll l = 1 , r = n + n ;
        while (l < r){
            ll mid = l + (r - l) / 2 ;
            if (check(n , mid) < m){
                l = mid + 1 ;
            }
            else{
                r = mid ;
            }
        }
        cout << l << endl ;
    }
}
