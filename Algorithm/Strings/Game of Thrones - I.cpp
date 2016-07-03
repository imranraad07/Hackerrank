#include <bits/stdc++.h>
using namespace std;
int arr[256] ;
int main() {
    string s ;
    cin >> s ;
    int i , l = s.length() , od = 0 , ev = 0 ;
    for(i = 0 ; i < l ; i++)    arr[s[i]]++ ;
    for(i = 'a' ; i <= 'z' ; i++){
        if(arr[i] == 0) continue ;
        if(arr[i]%2)    od++ ;
        else    ev++ ;
    }
    if(od > 1) cout << "NO" << endl ;
    else    cout << "YES" << endl ;
}
