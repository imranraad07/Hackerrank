#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
        string s1 , s2 ;
        cin >> s1 >> s2 ;
        char arr[256] ;
        memset(arr,0,sizeof(arr)) ;
        for(int i = 0 ; i < s1.length() ; i++){
            arr[s1[i]]++ ;
        }
        for(int i = 0 ; i < s2.length() ; i++){
            arr[s2[i]]-- ;
        }
        int ret = 0 ;
        for(int i = 0 ; i < 256 ; i++){
            ret += abs(arr[i]) ;
        }
        cout<< ret<<endl;
}
