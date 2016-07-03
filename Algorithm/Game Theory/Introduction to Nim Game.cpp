#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int main(){
    int T ;
    cin >> T ;
    while(T--){
        int n , a , i , ret = 0 ;
        cin >> n ;
        for(i = 0 ; i < n ; i++){
            cin >> a ;
            ret^=a;
        }
        if(ret) cout<<"First\n";
        else    cout<<"Second\n";
    }
}
