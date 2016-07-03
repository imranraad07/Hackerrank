#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[200005] ;
int main() {
    int n , k , q ;
    cin >> n >> k >> q ;
    k = k % n ;
    for(int i = 0 ; i < n ; i++)    cin >> arr[i];
    for(int i = n ; i < n+n ; i++)  arr[i] = arr[i-n] ;
    int a ;
    while(q--){
        cin >> a ;
        cout << arr[n-k+a] << endl;
    }
    return 0;
}
