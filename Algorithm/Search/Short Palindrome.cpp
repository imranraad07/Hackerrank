#include <bits/stdc++.h>
using namespace std ;
#define MOD 1000000007
int a4[130][130] ;
int a3[130][130] ;
int a2[130][130] ;
int a[130] ;

int main(){
    string s ;
    cin >> s ;
    int sz = s.size() ;
    for(int j = 0 ; j < sz ; j++){
        int u = s[j] ;
        for(int i = 'a' ; i <= 'z' ; i++){
            a4[i][u] = (a4[i][u] + a3[u][i]) % MOD ;
            a3[i][u] = (a3[i][u] + a2[i][u]) % MOD ;
            a2[i][u] = (a2[i][u] + a[i]) % MOD ;
        }
        a[u]++ ;
    }

    int ret = 0 ;
    for(int i = 'a' ; i <= 'z' ; i++){
        for(int j = 'a' ; j <= 'z' ; j++){
            ret = (ret + a4[i][j]) % MOD ;
        }
    }
    cout << ret << "\n" ;
}
