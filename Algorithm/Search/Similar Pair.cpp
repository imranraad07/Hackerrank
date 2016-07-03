#include <bits/stdc++.h>
using namespace std;
#define maxN 300010
#define ll long long

struct binaryIndexTree{
    ll total[maxN+5];
    void add(int i,ll val){
        while(i <= maxN){
            total[i] += val;
            i += (i & -i);
        }
    }
    ll get(int i){
        ll res = 0;
        while(i > 0){
            res += total[i];
            i -= (i & -i);
        }
        return res;
    }
};

binaryIndexTree BIT;
int deg[100005] ;
vector <int>v[100005] ;
int n , Val ;

ll f(int x){
    int l = max(1,x-Val) ;
    int r = min(n,x+Val) ;
    ll ret = BIT.get(r) - BIT.get(l-1) ;
    BIT.add(x , 1);
    int sz = v[x].size() ;
    for(int i = 0 ; i < sz ; i++){
        ret += f(v[x][i]) ;
    }
    BIT.add(x , -1);
    return ret ;
}

int main(){
    scanf("%d %d" , &n , &Val) ;
    int x , y ;
    for(int i = 0 ; i < n - 1; i++){
        scanf("%d %d" , &x , &y) ;
        v[x].push_back(y) ;
        deg[y] = true ;
    }

    int root ;
    for(int i = 1 ; i <= n ; i++){
        if(deg[i] == false)  root = i ;
    }

    printf("%lld\n" , f(root)) ;
}
