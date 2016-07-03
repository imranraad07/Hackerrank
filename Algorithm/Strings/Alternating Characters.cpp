#include <bits/stdc++.h>
using namespace std;
int main(){
    int T ;
    cin >> T ;
    while(T--){
        string s , ss ;
        cin >> s ;
        int l = s.length() , i , del = 0 ;
        for(i = 1 ; i < l ; i++){
            if(s[i] == s[i-1])  del++ ;
        }
        cout << del << endl ;
    }
}
