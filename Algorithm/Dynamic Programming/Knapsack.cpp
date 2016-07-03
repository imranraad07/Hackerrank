#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool arr[4010] ;
int main() {
    int T ;
    cin >> T ;
    while(T--){
        ll a , n , m ;
        cin >> n >> m ;
        arr[0] = true ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            for(int j = a ; j <= m+a ; j++){
                if(arr[j-a])
                    arr[j] = true ;
            }
        }
        for(int i = m ; i >= 0 ; i--){
            if(arr[i]){
                cout<<i<<endl;
                break;
            }
        }
        memset(arr ,  0 , sizeof(arr)) ;
    }
    return 0;
}
