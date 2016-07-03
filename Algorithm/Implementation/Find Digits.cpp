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
        cin >> n;
        int c , m = n , ret = 0 ;
        while(m){
            c = m%10 ;
            m/=10 ;
            if(c && n%c ==0)    ret++ ;
        }
        cout<<ret<<endl;
    }
    return 0;
}
