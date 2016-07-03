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
        string s ;
        cin >> s ;
        bool flag = true ;
        while(next_permutation(s.begin(),s.end())){
            cout<<s<<endl;
            flag = false ;
            break;
        }
        if(flag)    cout<<"no answer\n" ;
    }
    return 0;
}
