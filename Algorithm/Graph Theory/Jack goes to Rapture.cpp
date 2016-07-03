#include<bits/stdc++.h>
using namespace std ;
#define mp make_pair
#define ll long long
#define pii pair <int , int >
#define ff first
#define ss second
vector < pii > v[50002] ;
int n , m ;
int zcost[50002] ;
void bfs2(){
    for(int i = 0 ; i <= n ; i++){
        zcost[i] = (1<<30) ;
    }
    queue < pair<int,int> > q;
    for(int i = 0 ; i < v[1].size() ; i++){
        q.push(v[1][i]) ;
        zcost[v[1][i].ss] = v[1][i].ff ;
    }
    pii tmp;
    int x , y , z , i , sz ;

    while(!q.empty()){
        tmp = q.front() ;
        q.pop();

        y = tmp.first; /// cost
        x = tmp.second; /// node

        sz = v[x].size() ;

        for(i = 0 ; i < sz ; i++){
            z = max(v[x][i].ff - y , 0 ) ;
            if(y + z < zcost[v[x][i].ss]){
                zcost[v[x][i].ss] = y + z ;
                q.push(make_pair(y + z , v[x][i].ss));
            }
        }
    }
    if(zcost[n] == (1<<30))   puts("NO PATH EXISTS") ;
    else    printf("%d\n" , zcost[n]) ;
}


int main(){
    scanf("%d %d" , &n , &m) ;
    int a , b , i , c  ;
    for(i = 1 ; i <= m ; i++){
        scanf("%d %d %d" , &a , &b , &c) ;
        v[a].push_back(mp(c,b));
        v[b].push_back(mp(c,a));
    }
    bfs2();
}
Jack goes to Rapture