#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>
using namespace std;
vector<int>v[1000005] ;
int arr[1000005] ;
vector<int> ret ;
set<int>c;
int main() {
    int n ;
    cin >> n ;
    int k , a , b ;
    for(int i = 0 ; i < n ; i++){
        cin >> k ;
        cin >> a ;
        c.insert(a) ;
        for(int j = 1 ; j < k ; j++){
            cin >> b ;
            v[a].push_back(b) ;
            a = b ;
            arr[b]++ ;
        }
    }
    int r = 0 , z = 0 ;
    priority_queue<int>pq ;
    while(pq.size())    pq.pop() ;
    for(auto i : c){
        if(!arr[i]){
            pq.push(-i) ;
        }
    }
    while(pq.size()){
        int u = -pq.top() ;
        ret.push_back(u);
        pq.pop() ;
        for(auto i : v[u]){
            if(arr[i] == 0) continue ;
            arr[i]-- ;
            if(!arr[i]) pq.push(-i) ;
        }
    }
    for(auto i : ret){
        cout << i << ' ' ;
    }cout << endl;
}
