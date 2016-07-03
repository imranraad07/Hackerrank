#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int dx[] = {-2,-2,1,-1} ;
int dy[] = {1,-1,-2,-2} ;
int arr[16][16] ;
int grundyPosition(int x , int y){
    if(arr[x][y] != -1) return arr[x][y] ;
    set<int>s ; s.clear() ;
    for(int i = 0 ; i < 4 ; i++){
        if(x + dx[i] >= 0 && x + dx[i] < 15 &&
           y + dy[i] >= 0 && y + dy[i] < 15){
            s.insert(grundyPosition(x+dx[i],y+dy[i])) ;
        }
    }
    int ret = 0;
    while(s.find(ret) != s.end())  ret++ ;
    return arr[x][y] = ret ;
}

int main(){
    int T ;
    cin >> T ;
    memset(arr , -1 , sizeof(arr)) ;
    while(T--){
        int x , y ;
        cin >> x >> y ;
        x--; y--;
        if(grundyPosition(x,y)) cout<<"First"<<endl;
        else    cout<<"Second"<<endl;
    }
}
