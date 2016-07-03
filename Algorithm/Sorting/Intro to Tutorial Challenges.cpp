#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int v ;
    cin >> v ;
    int n ;
    cin >> n ;
    int a , ret = -1 , i ;
    for(i = 0 ; i < n ; i++){
        cin >> a;
        if(a == v){
            ret = i ;
        }
    }
    cout<<ret<<endl;
    return 0;
}
