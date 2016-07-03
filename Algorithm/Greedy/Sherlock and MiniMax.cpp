#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n ;
    cin>> n ;
    int arr[102] ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    sort(arr , arr + n) ;
    int p , q ;
    cin >> p >> q ;
    vector <int> v ;
    v.clear() ;
    v.push_back(p) ;
    v.push_back(q) ;

    for(int i = 1 ; i < n ; i++){
        v.push_back((arr[i]+arr[i-1])/2) ;
        v.push_back((arr[i]+arr[i-1])/2 + 1) ;
        v.push_back((arr[i]+arr[i-1])/2 - 1) ;
    }
    int dif = -1 ;
    int u = q + 1 ;
    int sz = v.size() ;
    sort(v.begin() , v.end()) ;
    for(int i = 0 ; i < sz ; i++){
        if(v[i] >= p && v[i] <= q){
            int k = q + 1 ;
            for(int j = 0 ; j < n ; j++){
                k = min(k , abs(arr[j] - v[i])) ;
            }
            if(k > dif){
                dif = k ;
                u = v[i] ;
            }
        }
    }
    cout << u << endl;
}
