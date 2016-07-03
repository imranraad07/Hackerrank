#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a ;
    double p = 0 , m = 0 , z = 0 ;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> a ;
        if(a < 0)   m++ ;
        else if(a > 0)  p++ ;
        else    z++ ;
    }
    cout.precision(15) ;
    cout<<p/n<<endl;
    cout<<m/n<<endl;
    cout<<z/n<<endl;
    return 0;
}
