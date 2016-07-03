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
        int k;
        cin >> n >> k;
        int a;
        int u = 0 ;
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a;
            if(a<=0) u++ ;
        }
        if(u<k)    cout<<"YES\n";
        else    cout<<"NO\n";
    }
    return 0;
}
