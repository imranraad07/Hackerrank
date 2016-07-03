#include <bits/stdc++.h>
using namespace std ;
char s[105];
int main(){
    int T ;
    cin >> T ;
    while(T--){
        cin >> s ;
        int n = strlen(s) , a = 0 , b = 0 , c = 0 ;
        for(int i = 0 ; s[i] ; i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++ ;
        }
//        cout<<a<<' '<<b<<' '<<c<<endl;
        if(a%2 == b%2 && b%2 == c%2)    cout << 2 << endl;
        else if(a == n || b == n || c == n)    cout << n << endl;
        else    cout << 1 << endl;
    }
}
