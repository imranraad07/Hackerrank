#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int main(){
    int T , c = 0 ;
    cin >> T ;
    while(T--){
        int n ;
        ll a , ret = 0 , e = 0 , o = 0 ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> a;
            if(a%2) ret ^= (i);
        }
        if(ret)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
}
