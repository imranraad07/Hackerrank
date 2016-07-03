#include<bits/stdc++.h>
using namespace std ;

int cost[3002][3002] ;
vector <int> v[3002] ;
int n , m , k ;
int zcost[3002] ;
void bfs(){
    for(int i = 0 ; i <= n ; i++){
        zcost[i] = (1<<30) ;
    }
    queue < pair<int,int> > q;
    q.push(make_pair(k,0)) ;
    pair<int,int>tmp;
    int x , y ;
    zcost[k] = 0 ;
    while(!q.empty()){
        tmp = q.front() ;
        q.pop();
        x = tmp.first;
        y = tmp.second;
        int i , sz = v[x].size() ;
        for(i = 0 ; i < sz ; i++){
            if(y + cost[x][v[x][i]] < zcost[v[x][i]]){
                zcost[v[x][i]] = y + cost[x][v[x][i]] ;
                q.push(make_pair(v[x][i],zcost[v[x][i]]));
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(zcost[i] == (1<<30)) zcost[i] = -1 ;
        if(i != k)  cout<<zcost[i]<<' ';
    }
    cout<<endl ;
}
void reset(){
    memset(cost,0,sizeof(cost));
    for(int i = 0 ; i <= n ; i++)   v[i].clear() ;
}
int main(){
    int T ;
    cin >> T ;
    while(T--){
        scanf("%d %d",&n,&m);
        int a , b , i , c  ;
        for(i = 1 ; i <= m ; i++){
            scanf("%d %d",&a,&b);
            scanf("%d",&c);
            if(cost[a][b] > c || cost[a][b] == 0){
                cost[a][b] = c ;
                cost[b][a] = cost[a][b];
            }
            v[a].push_back(b);
            v[b].push_back(a);
        }
        scanf("%d" , &k) ;
        bfs();
        reset();
    }
}
