#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int arr[205] ;
int main(){
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
        arr[n+i] = arr[i] ;
    }
    int u = 0 ;
    int s = 0 ;
    while(s < n-1){
        u++ ;
        s++ ;
        if(!arr[s + 1]){
            s++ ;
        }
//        cout << s << endl ;
    }
    cout << u << endl ;
}
