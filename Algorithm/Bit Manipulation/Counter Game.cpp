#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool pw2(unsigned long long int v){
    return (v & (v - 1)) == 0 ;
}

unsigned long long int lpw2(unsigned long long int  v){
    v--;
    v |= v >> 1 ;
    v |= v >> 2 ;
    v |= v >> 4 ;
    v |= v >> 8 ;
    v |= v >> 16 ;
    v |= v >> 32 ;
    v = v >> 1 ;
    v = v + 1 ;
    return v ;
}

int main() {
    int T ;
    cin >> T ;
    while(T--){
        unsigned long long int n ;
        cin >> n ;
        int mov = 0 ;
        while(1){
            if(n == 1)  break ;
            if(mov == 0)    mov = 1;
            else    mov = 0 ;

            if(pw2(n))  n/= 2 ;
            else{
                n = n-lpw2(n);
            }

//            cout<<n<<endl;
        }
        if(mov == 0) cout<<"Richard\n";
        else    cout<<"Louise\n";
    }
    return 0;
}
