#include <bits/stdc++.h>
using namespace std;
int main(){
    int T ;
    cin >> T ;
    while(T--){
        int n ;
        cin >> n ;
        int arr[n] ;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i] ;
        }
        sort(arr , arr+n) ;

        int ret = 1e9 ;

        for(int x = arr[0] - 5 ; x <= arr[0] ; x++){
            int u = 0 , k ;
            for(int i = 0 ; i < n ; i++){
                k = arr[i] - x ;
                u += k/5 ; k %= 5 ;
                u += k/2 ; k %= 2 ;
                u += k/1 ; k %= 1 ;
            }
//            cout << x << ' ' << u << endl ;
            ret = min(ret , u) ;
        }

        cout << ret << endl ;
    }
}
