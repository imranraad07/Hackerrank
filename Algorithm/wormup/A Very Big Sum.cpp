#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 

int main(){
    int n;
    cin >> n;
    ll ret = 0 , a ;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> a;
        ret += a;
    }
    cout<<ret<<endl;
    return 0;
}
