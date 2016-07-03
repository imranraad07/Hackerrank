#include <bits/stdc++.h>
using namespace std;
#define N 1010

vector<int>Graph[N];
bool vis[N];
int street[N];
int n;

int dfs(int x){
    int i,sz=Graph[x].size(),a;
	for(i=0;i<sz;i++){
	    a = Graph[x][i];
		if(!vis[a]){
			vis[a]=1;
			if(street[a]==-1||dfs(street[a])){
				street[a]=x;
				return 1;
			}
		}
	}
	return 0;
}
int f(){
	int ans = 0,i;
	for(i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		ans += dfs(i);
	}
	return ans ;
}
void reset(){
    int i;
    for(i=0;i<N;i++)    Graph[i].clear();
    memset(street,-1,sizeof(street));
}
int arr[1010] ;
int main() {
	int T,m;
	scanf("%d", &T);
	while(T--) {
	    reset();
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;i++){
            scanf("%d" , &arr[i]) ;
		}
		for(int i=0;i<n;i++){
            for(int j = i + 1 ; j <n;j++){
                if(abs(arr[i]-arr[j]) >= m){
                    Graph[i].push_back(j) ;
                }
            }
		}
        printf("%d\n",n-f());
	}
	return 0;
}
