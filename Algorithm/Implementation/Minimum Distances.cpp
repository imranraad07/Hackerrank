#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int arr[10005] ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    int r = n + 2 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i!= j && arr[i] == arr[j]){
                r = min(r , abs(i-j)) ;
            }
        }
    }
    if(r > n)   r  = -1 ;
    cout << r << "\n" ;
}
