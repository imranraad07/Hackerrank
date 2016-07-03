#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n , k , i , j , a , r = 0 , p = 1 ;
    cin >> n >> k ;
    for(i = 0 ; i < n ; i++){
        cin >> a ;
        for(j = 1 ; j <= a ; j++){
            if(j == p)  r++ ;
            if(j%k == 0 || j == a)    p++ ;
        }
    }
    cout<<r<<endl;
    return 0;
}
