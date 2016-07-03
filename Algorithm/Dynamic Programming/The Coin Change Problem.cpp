#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
ll arr[350] ;
int main() {
    ll a , n , m ;
    cin >> n >> m ;
    arr[0] = 1 ;
    for(int i = 0 ; i < m ; i++){
        cin >> a ;
        for(int j = a ; j <= n+a ; j++){
            arr[j] += arr[j-a] ;
        }
    }
    cout<<arr[n]<<endl;
    return 0;
}
