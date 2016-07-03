#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector<int>v[1010] ;
int cost[1010] ;

void bfs(int n , int s){
    queue<pair<int,int> >q ;
    pair<int,int> t ;
    q.push(make_pair(s,0)) ;
    while(!q.empty()){
        t = q.front() ;
        q.pop() ;
        int l = v[t.ff].size() ;
        for(int i = 0 ; i < l ; i++){
            if(cost[v[t.ff][i]] == -1){
                cost[v[t.ff][i]] = t.ss + 6 ;
                q.push(make_pair(v[t.ff][i],t.ss + 6)) ;
            }
            else if(t.ss + 6 < cost[v[t.ff][i]]){
                cost[v[t.ff][i]] = t.ss + 6 ;
                q.push(make_pair(v[t.ff][i],t.ss + 6)) ;
            }
        }
    }
}

int main(){
    int T ;
    scanf("%d",&T) ;
    while(T--){
        int n , m ;
        scanf("%d %d",&n,&m) ;
        int x , y , i , j ;
        for(i = 0 ; i < m ; i++){
            scanf("%d %d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        int s ;
        scanf("%d",&s) ;

        memset(cost,-1,sizeof(cost));

        bfs(n,s);

        for(int i = 1 ; i <= n ; i++){
            if(i!=s){
                printf("%d ",cost[i]) ;
            }

            v[i].clear() ;
        }
        puts("") ;
    }
}

