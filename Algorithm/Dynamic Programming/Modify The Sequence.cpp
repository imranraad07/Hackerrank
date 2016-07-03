#include <bits/stdc++.h>
using namespace std;
int main() {
    int n , a ;
    cin >> n ;
    vector < int > v ; v.clear() ;
    int idx ;
    for(int i = 0 ; i < n ; i++){
        cin >> a ;
        a -= i ;
//        cout << a << ' ';
        if(a > 0){
            idx = upper_bound(v.begin(),v.end() , a) - v.begin() ;
            if(idx != v.size()){
                v[idx] = a;
            }
            else{
                v.push_back(a) ;
            }
        }
    }
    cout << n - v.size() ;
//    cout<<endl;
//    cout<<v.size()<<endl;
//    for(int i = 0 ; i < v.size() ; i++){
//        cout << v[i] << ' ' ;
//    }cout<<endl;
}
