#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int T ;
    cin >> T ;
    while(T--){
        string s1 , s2 ;
        cin >> s1 >> s2 ;
        char arr[256] ;
        memset(arr,0,sizeof(arr)) ;
        for(int i = 0 ; i < s1.length() ; i++){
            arr[s1[i]] = true ;
        }
        bool flag = false ;
        for(int i = 0 ; i < s2.length() ; i++){
            if(arr[s2[i]]){
                flag = true ;
                break ;
            }
        }
        if(flag)    cout<<"YES\n";
        else    cout<<"NO\n";
    }
    return 0;
}
