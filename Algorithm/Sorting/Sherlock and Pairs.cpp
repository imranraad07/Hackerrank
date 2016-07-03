#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<int>v ;
int main() {
    int t , n , a  ;
    cin >> t ;
    while(t--){
        cin >> n ;
        v.clear() ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            v.push_back(a) ;
        }
        sort(v.begin() , v.end()) ;
        ll ret = 0 , u = 1 ;
        for(int i = 1 ; i < n; i++){
            if(v[i] == v[i-1])  u++;
            else{
                ret += u*(u-1) ;
                u = 1 ;
            }
        }
        ret += u*(u-1) ;
        cout << ret << endl ;
    }
}
