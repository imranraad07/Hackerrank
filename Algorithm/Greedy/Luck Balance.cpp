#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector < pair<int,int> > v ;
int main() {
    int n , k ;
    scanf("%d %d" , &n , &k) ;
    int l , t ;
    for(int i = 0 ; i < n ; i++){
        scanf("%d %d" , &l , &t) ;
        v.push_back( {l , t} ) ;
    }
    sort(v.begin() , v.end()) ;
    reverse(v.begin() , v.end()) ;
    int ret = 0 ;
    for(auto i : v){
        if(i.second == 0)  ret += i.first ;
        else{
            if(k)   ret += i.first , k-- ;
            else    ret -= i.first ;
        }
    }
    printf("%d\n" , ret) ;
}
