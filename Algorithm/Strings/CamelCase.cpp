#include<bits/stdc++.h>
using namespace std;
int main(){
    string s ;
    int r = 1 ;
    cin >> s ;
    for(auto i : s){
        if(i >= 'A' && i <= 'Z')    r++ ;
    }
    cout << r << endl ;
}
