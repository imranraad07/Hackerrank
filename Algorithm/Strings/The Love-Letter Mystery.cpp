#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T ;
    cin >> T;
    while(T--){
        string s ;
        cin >> s ;
        int j , l = s.size() , ret = 0 , i ;
        for(i = 0 , j = l-1 ; i < j ; j--, i++){
            ret += abs(s[i]-s[j]) ;
        }
        cout << ret << endl ;
    }
    return 0;
}
