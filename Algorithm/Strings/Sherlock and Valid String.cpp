#include <bits/stdc++.h>
using namespace std;
int cnt[256] ;
int main(){
    string s ;
    cin >> s ;
    sort(s.begin() , s.end()) ;
    int i , n = s.size() ;
    for(i = 0 ; i < n ; i++){
        cnt[s[i]]++ ;
    }
    int c = cnt[s[0]] , h = 0 , u = 0 , j ;
    for(i = 'a' ; i <= 'z' ; i++){
        if(cnt[i])  u++ ;
    }
    bool flag = false ;
    for(i = 'a' ; i <= 'z' ; i++){
        h = 0 ;
        for(j = 'a' ; j <= 'z' ; j++){
            if(cnt[i] == cnt[j])    h++ ;
        }
        if(abs(h-u) <= 1)   flag = true ;
    }
    if(flag)    cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
}
