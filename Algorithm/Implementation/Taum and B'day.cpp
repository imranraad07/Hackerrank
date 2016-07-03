#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 

int main() {
    int T ;
    cin >> T ;
    while(T--){
        ll b,w,x,y,z;
        cin >> b >> w >> x >> y >> z ;
        cout << min(b*x+w*y , min(b*x+w*x+w*z ,
                                 b*y+w*y+b*z )) << endl ;
    }
    return 0;
}
