#include <bits/stdc++.h>
using namespace std;
set < int > X ;
vector < pair < int , int > > v ;

int main(){
    int n , a , b ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b ;
        v.push_back( {a + b , a - b} ) ;
    }
    sort(v.begin() , v.end()) ;
    for(int i = 0 ; i < n ; i++){
        if(X.size()){
            auto x = X.lower_bound(v[i].second) ;
            if(*x == v[i].second ){
                continue ;
            }
            if(x != X.begin()){
                X.erase(--x) ;
            }
        }
        X.insert(v[i].second) ;
    }
    cout << X.size() << endl ;
}
