#include <bits/stdc++.h>
using namespace std;
#define MAXN 200100
#define ll long long
struct edge{
    ll u,v,w;
    bool operator < ( const edge& p ) const{
        return w < p.w;
    }
};

vector <edge> GRAPH ;
ll parent[MAXN] ;
edge e1;

ll find(ll x){
    if(parent[x]==x)    return x;
    return parent[x] = find(parent[x]);
}

vector<pair<ll,ll > >v1[MAXN] ;
ll n , m ;

void mst(){
    sort(GRAPH.begin(), GRAPH.end());
    ll u , v ;
    for(ll i=0; i<m; i++){
        u = find(GRAPH[i].u);
        v = find(GRAPH[i].v);
        if(u!=v){
            parent[u] = parent[v];
            v1[GRAPH[i].u ].push_back(make_pair(GRAPH[i].v , GRAPH[i].w)) ;
            v1[GRAPH[i].v ].push_back(make_pair(GRAPH[i].u , GRAPH[i].w)) ;
        }
    }
}

ll d[MAXN] ;
ll f(ll x , ll pre){
    d[x] = 1 ;
    for(auto i : v1[x])
        if(i.first != pre)  d[x] += f(i.first , x) ;
    return d[x] ;
}

ll arr[MAXN] ;

void f2(ll x , ll pre , ll e = -1 ){
    if(e != -1) arr[e] = d[x]*(d[1] - d[x]) ;
    for(auto i : v1[x]){
        if(i.first != pre)  f2(i.first , x , i.second) ;
    }
}

string d2b(ll u){
    string s ; s.clear() ;
    while(u){
        s += (char)(u%2 + '0') ;
        u /= 2 ;
    }
    reverse(s.begin() , s.end()) ;
    return s ;
}

string f3(ll p , ll koita){
    string ret ; ret.clear() ;
    ret = d2b(koita) ;
    return ret ;
}

string ret1 ;
ll shit[50000005] ;
int main(){
    for(ll i=0;i<MAXN;i++)   parent[i]=i;
    scanf("%d %d",&n , &m) ;
    for(ll i=0;i<m;i++){
        scanf("%d %d %d",&e1.u,&e1.v,&e1.w) ;
        GRAPH.push_back(e1) ;
    }
    mst() ;
    f(1 , -1) ;
    f2(1 , -1) ;
    for(ll i = 0 ; i < m ; i++){
        if(arr[i]){
            ret1 = f3(i , arr[i]) ;
            ll sz1 = ret1.length() , sz2 = sz1 + i - 1 ;
            for(ll j = 0 ; j < sz1 ; j++){
                if(ret1[j] == '1'){
                    shit[sz2 - j]++ ;
                }
            }
        }
    }
    ret1.clear() ;
    ll carry = 0 ;
    for(ll i = 0 ; i < 50000005 ; i++){
        carry += shit[i] ;
        if(carry){
            if(carry%2 == 0){
                carry/=2 ;
                ret1 += '0' ;
            }
            else{
                carry/=2 ;
                ret1 += '1' ;
            }
        }
        else{
            ret1 += '0' ;
        }
    }
    while(carry){
        if(carry%2 == 0){
            carry/=2 ;
            ret1 += '0' ;
        }
        else{
            carry/=2 ;
            ret1 += '1' ;
        }
    }
    bool flag = false ;
    for(ll i = ret1.length()-1 ; i >= 0 ; i--){
        if(flag)    printf("%c" , ret1[i]) ;
        else if(ret1[i] == '1'){
            flag = true ;
            printf("%c" , ret1[i]) ;
        }
    }
    printf("\n") ;
}
