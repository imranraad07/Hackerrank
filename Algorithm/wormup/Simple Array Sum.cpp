#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    int ret = 0 ;
    int a ;
    for(int arr_i = 0;arr_i < n;arr_i++){
        cin >> a ;
        ret += a;
    }
    cout << ret << endl;
    return 0;
}
