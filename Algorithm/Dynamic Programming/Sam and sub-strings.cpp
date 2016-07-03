#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define mod 1000000007
int main(){
    string s ;
    cin >> s;
    int n = s.length() ;
    ll u = 0 , v = 1;
    for(int i = n-1 ; i >= 0 ; i--){
        u = (u + (s[i]-'0')*v*(i+1))%mod ;
        v = (v*10 + 1) % mod ;
    }
    cout << u << endl ;
}
