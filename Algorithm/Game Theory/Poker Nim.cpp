#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int main(){
    int T , c = 0 ;
    cin >> T ;
    while(T--){
        int n , k , a , ret = 0 ;
        cin >> n >> k ;
        for(int i = 0 ; i < n ; i++){
            cin >> a;
            ret ^= a;
        }
        if(ret)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
}
