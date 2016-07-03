#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int main(){
    int T ;
    cin >> T ;
    while(T--){
        int n , a , i , ret = 0 , s = 0 ;
        cin >> n ;
        for(i = 0 ; i < n ; i++){
            cin >> a ;
            ret^=a;
            if(a == 1)  s++ ;
        }
        if(s == n){
            if(!ret) cout<<"First\n";
            else    cout<<"Second\n";
        }
        else{
            if(ret) cout<<"First\n";
            else    cout<<"Second\n";
        }
    }
}
