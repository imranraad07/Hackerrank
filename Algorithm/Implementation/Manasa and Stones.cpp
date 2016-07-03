#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T ;
    cin >> T;
    while(T--){
        int n , a , b ;
        cin >> n >> a >> b ;
        if(a > b)   swap(a,b) ;
        int u = a*(n-1) ;
        set<int>v; v.clear();
        v.insert(u) ;
        for(int i = 1 ; i < n ; i++){
            u -= a ;
            u += b ;
            v.insert(u) ;
        }
        for(auto i : v){
            cout << i << ' ' ;
        }
        cout<<endl;
    }
    return 0;
}
