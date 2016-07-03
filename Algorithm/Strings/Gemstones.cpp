#include <bits/stdc++.h>
using namespace std;
int arr[256] ;
int main() {
    int n ; cin >> n ; int ret = 0 ;
    for(int i = 0 ; i < n ; i ++){
        string s ; cin >> s ;
        for(int j = 0 ; j < s.length() ; j++){
            if(arr[s[j]] == i)  arr[s[j]]++ ;
        }
    }
    for(int i = 'a' ; i<= 'z' ; i++){
        if(arr[i] == n) ret++ ;
    }
    cout << ret << endl ;
}
