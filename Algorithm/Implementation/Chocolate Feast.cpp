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
        int c;
        int m;
        cin >> n >> c >> m;
        int ret = n/c , k = ret ;
        while(k >= m){
            ret++;
            k -= m;
            k++ ;
        }
        cout<<ret<<endl;
    }
    return 0;
}
