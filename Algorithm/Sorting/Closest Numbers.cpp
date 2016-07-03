#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>v ;
int main() {
    int a , n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> a ;
        v.push_back(a) ;
    }
    sort(v.begin(),v.end());
    int u = v[1] - v[0] ;
    for(int i = 2 ; i < n ; i++){
        u = min(u , v[i] - v[i-1] ) ;
    }
    for(int i = 1 ; i < n ; i++){
        if(u == v[i] - v[i-1] ) {
            cout<<v[i-1]<<' '<<v[i]<<' ';
        }
    }
    cout<<endl;
    return 0;
}
