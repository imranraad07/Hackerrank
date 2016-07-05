#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int arr[505][505] ;
int cost[505][505] ;
int main(){
    ios_base::sync_with_stdio(0) ;
//    freopen("output.txt" , "w" , stdout) ;
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> arr[i][j]  ;
            cost[i][j] = 1e9 ;
        }
        arr[i][i] = 1e9 ;
    }

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            for (int k = 1; k <= n ; k++) {
                cost[i][j] = min(cost[i][j] , cost[i - 1][k] + arr[k][j]) ;
            }
        }
    }

    int p = 1e7 , q = 1 ;
    int u , v , x , y ;
    for (int i = 1 ; i <= n ; i++) {
        x = 0 ;
        y = 1 ;
        for (int j = 1 ; j <= n ; j++) {
            u = cost[n][i] - cost[j][i] ;
            v = n - j ;

            if(u * y > x * v) {
                x = u ;
                y = v ;
            }
        }
        if(x * q < y * p) {
            p = x ;
            q = y ;
        }
    }
    if(n == 2){
        p = arr[1][2] + arr[2][1] ;
        q = 2 ;
    }
    cout << p/__gcd(p,q) << '/' << q/__gcd(p,q) << "\n" ;
}
