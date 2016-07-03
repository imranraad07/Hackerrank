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
    for(int i = 0 ; i < n ; i++){
        cin >> a ;
        arr[a]++ ;
    }
    for(int i = 0 ; i<100 ; i++){
        cout << arr[i] << ' ' ;
    }cout << endl ;
    return 0;
}
