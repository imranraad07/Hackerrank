#include<bits/stdc++.h>
using namespace std ;
int cost[1005][1005] ;
vector <int> v[1005] ;
int fish[1<<12] ;
int t[1005] ;
int n , m , k ;
int zcost[1005] ;
void bfs2(){
    for(int i = 0 ; i <= n ; i++){
        zcost[i] = (1<<30) ;
    }
    queue < pair<int,int> > q;
    q.push(make_pair(0,n)) ;
    pair<int,int>tmp;
    int x , y ;
    zcost[n] = 0 ;
    while(!q.empty()){
        tmp = q.front() ;
        q.pop();
        y = tmp.first;
        x = tmp.second;
        int i , sz = v[x].size() ;
        for(i = 0 ; i < sz ; i++){
            if(y + cost[x][v[x][i]] < zcost[v[x][i]]){
                zcost[v[x][i]] = y + cost[x][v[x][i]] ;
                q.push(make_pair(zcost[v[x][i]],v[x][i]));
            }
        }
    }
}


int market[1<<11][1002] ;
int mask[1<<11] ;
vector<int>s1;
void bfs(){
    for(int i = 0 ; i < (1<<11) ; i++){
        for(int j = 0 ; j <= n ; j++){
            market[i][j] = (1<<30) ;
        }
        mask[i] = (1<<30) ;
    }

    queue < pair<int,pair<int,int> > > q;

    pair<int,pair<int,int> >tmp;
    q.push(make_pair(fish[1],make_pair(0,1))) ;

    int x , y , z , p , tmp1 ;

    while(!q.empty()){
        tmp = q.front() ;
        q.pop() ;
        z = tmp.first;          /// mask
        x = tmp.second.first;   /// cost
        y = tmp.second.second;  /// cur node

        if(market[z][y] < x + zcost[y]) continue ;
        market[z][y] = x + zcost[y] ;
        mask[z] = min(mask[z] , market[z][y]) ;

        int i , j , sz = v[y].size();

        for(i = 0 ; i < sz ; i++){
            p = v[y][i] ;
            tmp1 = z ;
            tmp1 |= fish[p] ;
            q.push(make_pair(tmp1 , make_pair(x + cost[y][p] , p))) ;
        }
    }
    int ret = (1<<30) , sz = s1.size() ;
    for(int i = 0 ; i <= (1<<k) ; i++){
        for(int j = 0 ; j <= (1<<k) ; j++){
            if( (i|j) == (1<<k)-1 ){
                ret = min(ret , max(mask[i],mask[j])) ;
            }
        }
    }
    printf("%d\n",ret) ;
}

int main(){

    scanf("%d %d %d",&n,&m,&k);
    int a , b , i , c  ;

    for(i = 0 ; i < n ; i++){
        scanf("%d",&t[i+1]);
        for(b = 0 ; b < t[i+1] ; b++){
            scanf("%d",&a);
            fish[i+1] |= (1 << (a-1));
        }
    }
    for(i = 1 ; i <= m ; i++){
        scanf("%d %d",&a,&b);
        scanf("%d",&cost[a][b]);
        cost[b][a] = cost[a][b];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs2();
    bfs();
}
