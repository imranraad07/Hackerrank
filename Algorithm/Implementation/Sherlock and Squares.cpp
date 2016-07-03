#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T ;
    cin >> T ;
    while(T--){
        int a , b ;
        cin >> a >> b ;
        cout<< (int)sqrt(b) - (int)sqrt(a-1)<<endl;
    }
    return 0;
}
