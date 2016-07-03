#include <bits/stdc++.h>
using namespace std;
bool mp[256] ;
int main(){
    char s[1000] ;
    gets(s) ;
    bool flag = true ;
    int l = strlen(s) , i ;
    for(i = 0 ; i < l ; i++){
        mp[s[i]] = true ;
        if(s[i] < 'a')  mp[s[i] + 'a'-'A'] = true ;
    }
    for(i = 'a' ; i <= 'z' ; i++){
        if(mp[i] != true) flag = false ;
    }
    if(flag)    cout << "pangram" << endl ;
    else        cout << "not pangram" << endl ;
}
