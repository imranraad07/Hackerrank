#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
vector<pii>v[1002];
int cost[1002][1026] ;
void bfs(int s , int e){
    queue<pii>q;
    while(q.size()) q.pop();
    q.push(mp(s,0)) ;
    cost[s][0] = true ;
    int ret = 1204 ;
    while(q.size()){
        pii u = q.front() ;
        if(u.ff == e)   ret = min(ret , u.ss) ;
        //cout<<u.ff<<' '<<u.ss<<endl;
        q.pop() ;
        for(auto i : v[u.ff]){
            if( cost[i.ff][u.ss|i.ss] == false){
                cost[i.ff][u.ss|i.ss] = true ;
                q.push(mp(i.ff , (u.ss|i.ss) ) ) ;
            }
        }
    }
    if(ret > 1024)  ret = -1 ;
    cout << ret << endl ;
}

int main(){
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int n , m ;
    cin >> n >> m ;
    int a , b , c ;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c ;
        v[a].push_back(mp(b,c)) ;
        v[b].push_back(mp(a,c)) ;
    }

    for(int i = 1 ; i <= n; i++){
        sort(v[i].begin() , v[i].end()) ;
    }

    int s , e ;
    cin >> s >> e ;
    bfs(s,e) ;
}