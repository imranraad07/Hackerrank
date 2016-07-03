#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>
using namespace std;
int n , s ;
int cost[200002] ;
map<int,map<int,int>> m ;
vector<int>tmp,v;
void bfs(){
    fill(cost , cost + n + 1 , 1e9) ;
    queue<int>q;
    while(q.size() != 0)    q.pop() ;
    cost[s] = 0 ;
    for(int i = 1 ; i <= n ; i++)   v.push_back(i) ;
    int u ;
    q.push(s) ;
    while(q.size() != 0){
        u = q.front() ;
        q.pop() ;
        int sz = v.size() ;
        tmp.clear() ;
        for(auto i : v){
            if(i == u){
                continue ;
            }
            if(m[i][u]){
                tmp.push_back(i) ;
                continue ;
            }
            if(cost[i] > cost[u] + 1){
                cost[i] = cost[u] + 1;
                q.push(i) ;
                tmp.push_back(i) ;
            }
        }
        v = tmp ;
    }

    for(int i = 1 ; i <= n ; i++){
        if(i == s)  continue ;
        cout << cost[i] << ' ' ;
    }cout<<endl;
}

int main(){
    //freopen("input.txt" , "r" , stdin) ;
    //freopen("output.txt" , "w" , stdout) ;
    int T ;
    cin >> T ;
    while(T--){
        int k , a , b ;
        cin >> n >> k ;
        for(int i = 0 ; i < k ; i++){
            cin >> a >> b ;
            m[a][b] = true ;
            m[b][a] = true ;
        }
        cin >> s ;
        bfs() ;
        m.clear() ;
    }
}
