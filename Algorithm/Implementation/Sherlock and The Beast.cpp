#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        bool flag = false ;
        int k = 0 ;
        for(int i = 0 ; i <= n ; i+=3){
            if((n-i)%5 == 0){
                k = i ;
                flag = true ;
            }
        }
        if(flag){
            for(int i = 0 ; i < k ; i++){
                cout<<5;
            }
            for(int i = k ; i < n ; i++){
                cout<<3;
            }
            cout<<endl;
        }
        else    cout << -1 << endl;
    }
    return 0;
}
