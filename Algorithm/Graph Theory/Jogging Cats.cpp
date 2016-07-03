#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
vector <int> v[50005] ;
vector <int> v2[50005] ;
int sz[50005] ;
pii tmp ;
queue < pii > q ;
pii t ;
int x,y,r1,p;
void bfs(int n){
    int i , j , sz1 ;
    ll ret = 0 ;
    while(!q.empty()){
        t = q.front() ;
        q.pop() ;
        x = t.first;
        y = t.second;

        bool flag ;
        for(i = 0 ; i < sz[x] ; i++){
            p = v[x][i] ;
            if(y < p){
                v2[y].push_back(p) ;
            }
        }
    }
    ll r ;
    for(i = 1 ; i <= n ; i++){
        sort(v2[i].begin() , v2[i].end()) ;
        sz1 = v2[i].size() ;
        r = 0 ;
        for(j = 0 ; j < sz1 ; j++){
            if(j == 0)  r++ ;
            else if(v2[i][j] == v2[i][j-1]) r++ ;
            else{
                ret += r*(r-1)/2 ;
                r = 1 ;
            }
        }
        ret += r*(r-1)/2 ;
    }
    printf("%lld\n",ret);
}
int main(){
    int n , m ;
    scanf("%d %d",&n,&m);
    int a , b , i ;
    for(i = 0 ; i < m ; i++){
        scanf("%d %d",&a,&b);
        if(a > b)   swap(a,b) ;
        v[a].push_back(b);
        v[b].push_back(a);
        q.push(mp(b,a));
    }
    for(i = 1 ; i <= n ; i++){
        sz[i] = v[i].size() ;
    }
    bfs(n);
}
