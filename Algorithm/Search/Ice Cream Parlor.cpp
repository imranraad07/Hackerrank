#include <bits/stdc++.h>
using namespace std;
int arr[10005] ;
int main() {
    int T ;
    cin >> T ;
    while(T--){
        int n , m ;
        cin >> m >> n ;
        for(int i = 1 ; i <= n ; i++)   cin >> arr[i] ;
        for(int i = 1 ; i < n ; i++){
            for(int j = i+1 ; j <= n ; j++){
                if(arr[i] + arr[j] == m){
                    cout << i << ' ' << j << "\n" ;
                }
            }
        }
    }
}
