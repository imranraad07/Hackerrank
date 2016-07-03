#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum[100005];
int main() {
    int T;
    cin >> T;
    while(T--){
        int i , n , a ;
        cin >> n ;
        sum[0] = 0 ;
        for(i = 1 ; i <= n ; i++){
            cin >> a ;
            sum[i] = sum[i-1] + a ;
        }

        for(i = 1 ; i <= n ; i++){
            if(sum[i-1] == sum[n]-sum[i]){
                cout<<"YES\n";
                break;
            }
        }
        if(i>n) cout<<"NO\n" ;
        
    
    }
    return 0;
}
