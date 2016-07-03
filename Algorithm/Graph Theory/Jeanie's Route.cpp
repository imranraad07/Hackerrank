#include<bits/stdc++.h>
using namespace std ;
#define mp make_pair
#define ll long long
#define pii pair <int , int >
#define ff first
#define ss second
vector < pii > v[100002] ;
int n , k ;
int arr1[100002] ;
bool vis[100002] ;
int f(int pos , int pre){
    int ret = -(k+1) ;
    for (int i = 0 ; i <v[pos].size() ; i++){
        if(v[pos][i].ss == pre)  continue ;
        ret = max(ret , arr1[v[pos][i].ss] + f(v[pos][i].ss , pos)) ;
    }
    if(arr1[pos]) ret = 1 ;
    if(ret < 0) vis[pos] = 1 ;
    return ret;
}

int ret = 0 ;
void f2(int pos , int pre){
    for (int i = 0 ; i <v[pos].size() ; i++){
        if(v[pos][i].ss == pre)  continue ;
        if(vis[v[pos][i].ss])   continue ;
        f2(v[pos][i].ss , pos) ;
        ret += v[pos][i].ff ;
    }
}

int ret2 , far ;
void f3(int pos , int pre , int cost){
	if(cost > ret2){
		ret2 = cost;
		far = pos ;
	}
	for(int i = 0 ; i < v[pos].size() ; i++ ){
        if(v[pos][i].ss == pre)  continue ;
        if(vis[v[pos][i].ss])   continue ;
        f3(v[pos][i].ss , pos , cost + v[pos][i].ff) ;
	}
}

int main(){
    int a , b , i , c , p  ;
    scanf("%d %d" , &n , &k) ;
    for(i = 0 ; i < k ; i++){
        scanf("%d" , &p) ;
        arr1[p] = true ;
    }
    for(i = 1 ; i < n ; i++){
        scanf("%d %d %d" , &a , &b , &c) ;
        v[a].push_back(mp(c,b));
        v[b].push_back(mp(c,a));
    }
    f(p , -1) ;
    f2(p , -1) ;
    b = 0 ;
    f3(p , -1 , 0) ;
    f3(far , -1 , 0) ;
    cout << ret*2 - ret2 << endl;
}

