#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
vector<int>v[MAXN] ;
bool vis[MAXN];
queue<int>Q;
bool _1st[MAXN],_2nd[MAXN];

#define pii pair<int,int>
#define mp make_pair

int v1 , v2 ;

pii bfs(int src){
    Q.push(src) ;
    vis[src]=1 ;

    int k1 , k2 ;
    k1 = 1 ; k2 = 0 ;

    memset(_1st , 0 , sizeof(_1st)) ;
    memset(_2nd , 0 , sizeof(_2nd)) ;
    _1st[src]=true ;
    v1 = src ;

    int x , y ;
    while(!Q.empty()){
        x = Q.front() ;
        Q.pop() ;
        int sz = v[x].size() ;
        for(int i = 0 ; i < sz ; i++){
            y = v[x][i];

            if(!vis[y]){
                vis[y]=1;
                Q.push(y);
                if(_1st[x]){
                    k2++;
                    _2nd[y] = true ;
                    v2 = y ;
                }
                else{
                    k1++;
                    _1st[y] = true;
                    v1 = y ;
                }
            }
        }
    }

    return mp(k1,k2) ;
}
vector < pii > ret ;
vector < pii > bws ;
vector < pii > bws2 ;
vector < int > t ;
int idx[200001] ;
int dif[200001] ;
int arr[200001] ;
int main(){
//    freopen("input.txt" , "r" , stdin) ;
    int n , m ;
    scanf("%d %d",&n , &m);
    int x , y , k ;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        k = x ;
    }
    if(m == 0){
        printf("%d %d\n",m%2 , n-1) ;
        for(int i = 1 ; i < n ; i++){
            printf("%d %d\n",i , i+1) ;
        }
        return 0 ;
    }


    pii tmp ;
    int sum = 0 ;

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            tmp = bfs(i) ;
            bws.push_back(mp(v1 , v2)) ;
            dif[ ( (abs(tmp.first-tmp.second)) ) ] ++ ;
            sum += abs(tmp.first-tmp.second) ;
            t.push_back(abs(tmp.first-tmp.second)) ;
            bws2.push_back(tmp) ;
            v1 = 0 ; v2 = 0 ;
        }
    }

    int u = 0 ;
    int mndif = sum ;
    for(int i = 1 ; i <= sum ; i++){
        arr[i] = MAXN ;
    }
    for (int i=1;i<=n;i++){
        if(dif[i]){
            for (int j = 0 ; j + i <= sum ; j++){
                arr[i+j] = min(arr[i+j] , arr[j] + 1) ;
            }
            for (int j = 1 ; j <= sum ; j++){
                if (arr[j] > dif[i]){
                    arr[j] = MAXN;
                }
                else{
                    arr[j]=0;
                }
            }
        }
    }
    u = 0 ;
    for (int i = 0 ; i <= sum ; i++){
        if(arr[i] < MAXN){
            if(mndif > abs(i + i - sum)){
                mndif = abs(i + i - sum) ;
                u = i ;
            }
        }
    }
    int sz = t.size() ;
    for(int i = 0 ; i < sz ; i++){
        if(u - t[i] >= 0 && arr[u-t[i]] < sum){
            u -= t[i] ;
            idx[i] = 1 ;
            x = i ;
        }
        else{
            idx[i] = 2 ;
            y = i ;
        }
    }

//    for(int i = 0 ; i < bws.size() ; i++){
//        cout << bws[i].first << ' ' << bws[i].second << ' ' <<
//                bws2[i].first << ' ' << bws2[i].second << " " << idx[i] << endl;
//    }


    if(bws.size() > 1)
    for(int i = 0 ; i < bws.size() ; i++){
        if(idx[i] == 1){
            if(bws2[y].second > bws2[y].first){
                if(bws2[i].second > bws2[i].first)  u = bws[i].second ;
                else    u = bws[i].first ;
                ret.push_back(mp(bws[y].second , u)) ;
            }
            else{
                if(bws2[i].second > bws2[i].first)  u = bws[i].second ;
                else    u = bws[i].first ;
                ret.push_back(mp(bws[y].first , u)) ;
            }

        }
        else{
            if(bws2[x].second > bws2[x].first){
                if(bws2[i].second > bws2[i].first)  u = bws[i].second ;
                else    u = bws[i].first ;
                ret.push_back(mp(bws[x].second , u)) ;
            }
            else{
                if(bws2[i].second > bws2[i].first)  u = bws[i].second ;
                else    u = bws[i].first ;
                ret.push_back(mp(bws[x].first , u)) ;
            }
        }
    }

    printf("%d %d\n" , mndif , ret.size() ) ;
    for(int i = 0 ; i < ret.size() ; i++){
        printf("%d %d\n" , ret[i].first , ret[i].second ) ;
    }
}
