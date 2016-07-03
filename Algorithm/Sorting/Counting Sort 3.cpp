#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[105] ;
int main() {
    int n , a ;
    cin >> n ;
    string s ;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> s ;
        arr[a]++ ;
    }
    int k = 0 ;
    for(int i = 0 ; i<100 ; i++){
        k += arr[i] ;
        cout << k << ' ' ;
    }cout << endl ;
    return 0;
}