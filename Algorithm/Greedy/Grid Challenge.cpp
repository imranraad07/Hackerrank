#include <bits/stdc++.h>
using namespace std;

array<string,102> v;
array<string,2> ret = {"NO" , "YES"} ;

int main() {
    int T , n ;
    cin >> T ;
    while(T--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> v[i] ;
            sort(v[i].begin(),v[i].end()) ;
        }
        bool flag = true ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n - 1 ; j++){
                if( v[i][j] > v[i][j+1])   flag = false ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n - 1  ; j++){
                if( v[j][i] > v[j+1][i])   flag = false ;
            }
        }
        cout<<ret[flag]<<endl;
    }
    return 0;
}
