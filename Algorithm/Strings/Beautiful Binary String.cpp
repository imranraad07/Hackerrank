#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin >> n ;
    string s ;
    cin >> s ;
    int i = 0 ;
    while(s.find("010") != -1){
        s.replace(s.find("010") , 3 , "111");
        i++ ;
    }
    cout << i << endl ;
}
