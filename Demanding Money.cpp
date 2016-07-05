#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[50][50] ;
int group[50] ;
void gC(int x , int g) ;
int n , m ;
int c[50] ;
vector<int>v[50] ;
int vis[50] ;
int max_cost[50] ;
vector<int>g[50] ;
ll X[50] ;
/***bool isvalid(vector<int>x){
    int sz = x.size() ;
    for(int i = 0 ; i < sz ; i++){
        for(int j = i+1 ; j < sz ; j++){
            if(arr[x[i]][x[j]]){
                return false ;
            }
        }
    }
    return true ;
}
void subsets(vector<int>x , int grp){
    int sz = x.size() , u  ;
    vector < int > tmp ;
    for(int i = 0 ; i < (1LL<<sz) ; i++){
        tmp.clear() ;
        u = 0 ;
        for(int j = 0 ; j < sz ; j++){
            if(i & (1LL<<j)){
                tmp.push_back(x[j]) ;
                u += c[x[j]] ;
            }
        }
        if(isvalid(tmp)){
            if(max_cost[grp] < u){
                max_cost[grp] = u ;
                X[grp] = 1 ;
            }
            else if(max_cost[grp] == u){
                X[grp]++ ;
            }
        }
    }
}***/

vector<int>x ;
int grp , sz ;
bool check(ll mask , int pos) ;
void flash(int pos , ll mask , int cost) ;
void flash2(int pos , ll mask , int cost);
set < ll >my_set ;

int main(){
    ios_base::sync_with_stdio(0) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++){
        cin >> c[i] ;
    }
    int a , b ;
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b ;
        v[a].push_back(b) ;
        v[b].push_back(a) ;
        arr[a][b] = 1 ;
        arr[b][a] = 1 ;
    }
    int g1 = 1;
    memset(max_cost , -1 , sizeof(max_cost)) ;
    for(int i = 1 ; i <= n ; i++){
        if(group[i] == 0){
            gC(i , g1) ;
            g1++ ;
        }
        g[group[i]].push_back(i) ;
    }
    ll way = 1 , borow = 0 ;
    for(int i = 1 ; i < g1 ; i++){
//        subsets(g[i] , i) ;
        x = g[i] ;
        grp = i ;
        sz = g[i].size() ;
        my_set.clear() ;
        flash2(0,0,0) ;
        flash(0,0,0) ;
        borow += max_cost[i] ;
        //way = way*X[i] ;
        way = way*(my_set.size()) ;
    }
    cout << borow << ' ' << way << "\n" ;
}

void gC(int x , int g){
    if(group[x])    return ;
    group[x] = g ;
    for(auto i : v[x]){
        gC(i , g) ;
    }
}


void flash(int pos , ll mask , int cost){
    if(pos == sz){
        if(cost == max_cost[grp]){
            my_set.insert(mask) ;
            //cout << mask << endl ;
            //return ;
        }
        return ;
    }
    if(check(mask , pos))
        flash(pos + 1 , mask|(1LL<<pos) , cost + c[x[pos]]) ;
    flash(pos + 1 , mask , cost) ;
}

void flash2(int pos , ll mask , int cost){
//    cout << cost << endl ;
    if(pos == sz){
        max_cost[grp] = max(max_cost[grp] , cost) ;
        return ;
    }
    if(check(mask , pos))
        flash2(pos + 1 , mask|(1LL<<pos) , cost + c[x[pos]]) ;
    flash2(pos + 1 , mask , cost) ;
}

bool check(ll mask , int pos){
    for(int i = 0 ; i < sz ; i++){
        if(mask&(1LL<<i)){
            if(arr[x[i]][x[pos]]){
                return 0 ;
            }
        }
    }
    return 1 ;
}
