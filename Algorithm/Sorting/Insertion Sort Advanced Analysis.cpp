#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000010
ll BIT[MAX+2] ;

void update(int pos , ll val){
    for(;pos <= MAX ;){
        BIT[pos] += val ;
        pos += (pos&(-pos)) ;
    }
}

ll query(int pos){
//    cout<<pos<<endl;
    ll ret = 0 ;
    for(;pos > 0;)
    {
        ret += BIT[pos];
        pos &= (pos-1) ;
    }
    return ret ;
}
int main(){
//    freopen("input.txt" , "r" , stdin) ;
    int T ;
    cin >> T ;
    while(T--){
        int n , a; ll ret = 0 ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            ret += query(10000000) - query(a);
            update(a,1) ;
        }
        cout<<ret<<endl;
        memset(BIT , 0 , sizeof(BIT)) ;
    }
}
