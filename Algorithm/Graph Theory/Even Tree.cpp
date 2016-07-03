#include <bits/stdc++.h>
using namespace std ;
int arr[300005] ;
vector<int> G[300005] ;
int d[300005] ;
int ans ;
void f(int x , int pre){
//    cout << x << ' ' << pre << endl ;
    d[x] = 1 ;
    for(auto i : G[x]){
        if(i != pre){
            f(i , x) ;
            if(d[i]%2 == 0) ans++ ;
            else    d[x] += d[i] ;
        }
    }
}

int main(){
    int n , m , a , b ;
    cin >> n >> m ;
    for(int i = 2 ; i <= n ; i++){
        cin >> a >> b ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    f(1 , -1) ;

//    for(auto i = 1 ; i <= n ; i++){
//        cout << d[i] << ' ' ;
//    }cout << endl;

    cout << ans << endl;
}
