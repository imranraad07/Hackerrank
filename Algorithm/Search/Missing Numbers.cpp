#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005] ;

int main() {
    int n , m , i , a ;
    cin >> n ;
    for(i = 0 ; i < n ; i++){
        cin >> a;
        arr[a]++ ;
    }
    cin >> n ;
    for(i = 0 ; i < n ; i++){
        cin >> a;
        arr[a]-- ;
    }
    for(i = 1 ; i <= 10000 ; i++){
        if(arr[i])  cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}
