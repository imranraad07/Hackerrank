#include <bits/stdc++.h>
using namespace std ;
int main(){
//    for(int i = 0 ; i <= 20 ; i++){
//        cout << i << ' ' << (1LL<<i)%17 << endl;
//    }
    int T ;
    cin >> T ;
    while(T--){
        int n ;
        cin >> n ;
        if(n%8 == 0)    cout << "Second\n" ;
        else    cout << "First\n" ;
    }
}
