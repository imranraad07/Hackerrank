#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000
vector<int>v[10005] ;
int n , k ;
bool cy[100005] ;
ll dp[100005] ;
ll f(int x , int pre){
    if(x == n)  return 1 ;
    if(dp[x] != -1) return dp[x] ;
    ll ret = 0 ;
    int sz = v[x].size() ;
    for(int i = 0 ; i < sz ; i++){
        if(v[x][i] == pre || cy[x])  continue ;
        ret += f(v[x][i] , x) ;
    }
    return dp[x] = ret%mod ;
}
bool cycle ;
int vis[10002] ;
vector<int>blcok;
void f2(int x){
    if(vis[x]==2) return;
    if(vis[x]){
        cycle = 1 ;
        cy[x] = 1 ;
        blcok.push_back(x) ;
    }
    if(cy[x])   return ;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)  f2(v[x][i]);
    vis[x]=2;
}
bool v2[100002] ;
bool bfs(){
    queue<int>q ;
//    while(q.size() != 0)    q.pop() ;
//    for(int i = 0 ; i < blcok.size() ; i++){
//        q.push(blcok[i]) ;
//    }
    q.push(1) ;
    while(q.size() != 0){
        int u = q.front() ;
        q.pop() ;
        v2[u] = true ;
        for(int i = 0 ; i < v[u].size() ; i++){
            if(!v2[v[u][i]]){
                q.push(v[u][i]) ;
            }
        }
    }
    for(int i = 0 ; i < blcok.size() ; i++){
        if(v2[blcok[i]]){
            q.push(blcok[i]) ;
        }
    }
    memset(v2 , 0 , sizeof(v2)) ;
    while(q.size() != 0){
        int u = q.front() ;
        q.pop() ;
        v2[u] = true ;
        for(int i = 0 ; i < v[u].size() ; i++){
            if(!v2[v[u][i]]){
                q.push(v[u][i]) ;
            }
        }
    }
    return v2[n] ;
}

int main(){
    int a , b , m;
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b ;
        v[a].push_back(b) ;
    }
    f2(1) ;
//    for(auto i : blcok){
//        cout << i << ' ' ;
//    }cout << endl;
//    cout << bfs() << endl;
    if(bfs()){
        cout << "INFINITE PATHS" << endl;
        return 0 ;
    }
    memset(dp , -1 , sizeof(dp)) ;
    ll r = f(1,-1) ;
    cout << r << endl;
}
