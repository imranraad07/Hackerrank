#include <bits/stdc++.h>
using namespace std;
int main() {
    int n , a ;
    cin >> n ;
    cin >> a ;
    vector < int > v ; v.clear() ;
    v.push_back(a) ;
    int idx ;
    for(int i = 1 ; i < n ; i++){
        cin >> a ;
        idx = lower_bound(v.begin(),v.end() , a) - v.begin() ;
        if(idx != v.size()){
            v[idx] = a;
        }
        else{
            v.push_back(a) ;
        }
//        for(int j = 0 ; j < v.size() ; j++){
//            cerr<<v[j]<<' ';
//        }cerr<<endl;
    }
    cout<<v.size()<<endl;
}
