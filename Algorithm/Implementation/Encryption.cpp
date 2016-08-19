#include <bits/stdc++.h>
using namespace std ;
int main(){
    string s ;
    cin >> s ;
    int n = s.size() ;

    int m = sqrt(n) ;
    if(m*m < n) m++ ;
    
    cerr << n << ' ' << m << endl ;

    for(int i = 0 ; i < m ; i++){
        for(int j = i ; j < n ; j += m)
            printf("%c", s[j]) ;
        printf(i == m - 1 ? "\n" : " ") ;
    }
}
