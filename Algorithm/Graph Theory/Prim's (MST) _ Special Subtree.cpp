#include <bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
#define piii pair < int , pii >
#define mp make_pair

vector < piii > GRAPH;
int parent[10002] ;
int n , m , c ;

int find(int x){
    if(parent[x]==x)    return x ;
    return parent[x] = find(parent[x]) ;
}

int mst(){
    sort(GRAPH.begin(), GRAPH.end()) ;
    int total=0 ;
    for(int i = 0 ; i < m ; i++){
        int u = find(GRAPH[i].second.first) ;
        int v = find(GRAPH[i].second.second) ;
        if(u!=v){
            total += GRAPH[i].first ;
            parent[u] = parent[v] ;
        }
    }
    return total ;
}

void reset(){
    GRAPH.clear();
    for(int i = 0 ; i <= n ; i++)   parent[i] = i ;
}

int main(){
    cin >> n >> m ;
    reset();
    int a , b , c ;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c ;
        GRAPH.push_back( mp ( c , mp ( a , b ) ) ) ;
    }
    cin >> c ;
    cout<<mst()<<endl ;
}
