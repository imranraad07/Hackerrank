#include <bits/stdc++.h>
using namespace std;

int main(){
    int T ;
    int n , i , j , k ;
    cin >> T ;
    while(T--){
        cin >> n >> k ;
        if(k == 0){
            for(i = 1 ; i <= n ;i++){
                cout<<i<<' ';
            }
            cout<<endl;
            continue ;
        }
        if(n % (k*2) ) cout<<-1<<endl;
        else{
            i = 1 ;
            while(i<=n){
                for(j = 1 ; j <= k ; j++){
                    cout<<i+k<<' ';
                    i++;
                }
                for(j = 1 ; j <= k ; j++){
                    cout<<i-k<<' ';
                    i++;
                }
            }
            cout<<endl;
        }
    }
}
