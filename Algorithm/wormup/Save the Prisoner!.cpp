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
        int n , m , s ;
        cin >> n >> m >> s ;
        m = (m - 1 + s - 1)%n ;
        cout << m + 1 << endl ;
    }
}
