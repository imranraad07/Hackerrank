#include <bits/stdc++.h>
using namespace std;
int main(){
    int T ;
    cin >> T ;
    while(T--){
        string s , ss ;
        cin >> s ; ss = s ; reverse(ss.begin() , ss.end()) ;
        bool flag = true ;
        int l = s.length() , i ;
        for(i = 0 ; i < l-1 ; i++){
            if( abs(s[i]-s[i+1]) != abs(ss[i]-ss[i+1]) )    flag = false ;
        }
        if(flag)    cout << "Funny" << endl ;
        else        cout << "Not Funny" << endl ;
    }
}
