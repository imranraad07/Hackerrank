#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int t1[256] ;

int main() {
    int T ;
    cin >> T ;
    while(T--){
        string s;
        cin >> s;
        int i , l = s.size();
        if(l&1) cout<<-1<<endl;
        else{
            memset(t1 , 0 , sizeof(t1)) ;
            for(i = 0 ; i < l>>1 ; i++){
                t1[s[i]]++ ;      
            }
            for(i = l>>1 ; i < l ; i++){
                t1[s[i]]-- ;      
            }
            int r1 = 0 ;
            for(i = 0 ; i < 256 ; i++){
                if(t1[i] > 0)   r1 += t1[i];
            }
            cout<<r1<<endl;
        }
    }
    return 0;
}

