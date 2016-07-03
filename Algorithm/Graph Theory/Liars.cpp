#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
int n ;
int cost[105] ;
vector<pii>v[105] ;
vector<pii>v2[105] ;
void bfs(int s){
    fill(cost , cost + n + 1 , 1e9) ;
    queue<int>q;
    while(q.size() != 0)    q.pop() ;
    cost[s] = 0 ;
    int u ;
    q.push(s) ;
    while(q.size() != 0){
        u = q.front() ;
//        cout<<u<<endl;
        q.pop() ;
        int sz = v[u].size() ;
        for(auto i : v[u]){
            if(cost[i.first] > cost[u] + i.second){
                cost[i.first] = cost[u] + i.second ;
                q.push(i.first) ;
            }
        }
    }
//    cout<<cost[0]<<' '<<cost[1]<<endl;
    cout<<cost[0]<<endl;
}

void bfs2(int s){
    fill(cost , cost + n + 1 , -1e9) ;
    queue<int>q;
    while(q.size() != 0)    q.pop() ;
    cost[s] = 0 ;
    int u ;
    q.push(s) ;
    while(q.size() != 0){
        u = q.front() ;
//        cout<<u<<' '<<cost[u]<<endl;
        q.pop() ;
        int sz = v2[u].size() ;
        for(auto i : v2[u]){
            if(cost[i.first] < cost[u] + i.second){
                cost[i.first] = cost[u] + i.second ;
                q.push(i.first) ;
            }
        }
    }
    //cout<<cost[0]<<' '<<cost[1]<<endl;
    cout<<cost[0]<<' ';
}

int main(){
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
        int k , a , b , c ;
        cin >> n >> k ;
        for(int i = 0 ; i < n ; i++){
            v[i+1].push_back(mp(i , 1)) ;
            v[i].push_back(mp(i+1 , 0)) ;
            v2[i+1].push_back(mp(i , 0)) ;
            v2[i].push_back(mp(i+1 , -1)) ;
        }
        for(int i = 0 ; i < k ; i++){
            cin >> a >> b >> c ;
            v[b].push_back(mp(a-1,c)) ;
            v[a-1].push_back(mp(b,-c)) ;
            v2[b].push_back(mp(a-1,c)) ;
            v2[a-1].push_back(mp(b,-c)) ;
        }
        bfs2(n) ;
        bfs(n) ;
}
