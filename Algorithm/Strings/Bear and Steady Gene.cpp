#include <bits/stdc++.h>
using namespace std;
int n ;
string s ;

int arr[5][500005] ;

bool check(int l){
    int x[5] ;
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            x[0] = ( arr[0][n-1] - arr[0][i+l-1]) ;
            x[1] = ( arr[1][n-1] - arr[1][i+l-1]) ;
            x[2] = ( arr[2][n-1] - arr[2][i+l-1]) ;
            x[3] = ( arr[3][n-1] - arr[3][i+l-1]) ;

            if( (x[0] <= n/4) &&
               (x[1] <= n/4) &&
               (x[2] <= n/4) &&
               (x[3] <= n/4) ){
                return true ;
            }
        }
        else{
            x[0] = (arr[0][i-1] + arr[0][n-1] - arr[0][i+l-1]) ;
            x[1] = (arr[1][i-1] + arr[1][n-1] - arr[1][i+l-1]) ;
            x[2] = (arr[2][i-1] + arr[2][n-1] - arr[2][i+l-1]) ;
            x[3] = (arr[3][i-1] + arr[3][n-1] - arr[3][i+l-1]) ;

            if( (x[0] <= n/4) &&
               (x[1] <= n/4) &&
               (x[2] <= n/4) &&
               (x[3] <= n/4) ){
                return true ;
            }
        }
    }
    return false ;
}

int main() {
//    freopen("input.txt" , "r" , stdin) ;
    cin >> n ;
    cin >> s ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'A') arr[0][i]++;
        else if(s[i] == 'T') arr[1][i]++;
        else if(s[i] == 'G') arr[2][i]++;
        else if(s[i] == 'C') arr[3][i]++;
        arr[0][i+1] = arr[0][i] ;
        arr[1][i+1] = arr[1][i] ;
        arr[2][i+1] = arr[2][i] ;
        arr[3][i+1] = arr[3][i] ;
    }
    int l = 0 , r = n , mid ;
    while(l <= r){
        mid = (l+r)/2 ;
        if(check(mid)){
            r = mid - 1 ;
        }
        else{
            l = mid + 1 ;
        }
    }
    cout << l << endl ;
}
