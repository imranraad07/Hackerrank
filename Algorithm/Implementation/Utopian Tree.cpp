#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        ll k = 1 ;
        for(int i = 0 ; i < n ; i++){
            if(i%2){
                k += 1 ;
            }
            else{
                k *= 2 ;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
