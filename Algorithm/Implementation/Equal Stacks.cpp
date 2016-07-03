#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int arr1[100005] ;
int arr2[100005] ;
int arr3[100005] ;
int vis1[10000005] ;
int vis2[10000005] ;
int vis3[10000005] ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n1 , n2 , n3 ;
    cin >> n1 >> n2 >> n3 ;
    for(int i = 0 ; i < n1 ; i++)   cin >> arr1[i] ;
    for(int i = 0 ; i < n2 ; i++)   cin >> arr2[i] ;
    for(int i = 0 ; i < n3 ; i++)   cin >> arr3[i] ;
    int u ;
    u = 0 ;
    for(int i = n1 - 1 ; i >= 0 ; i--){
        u += arr1[i] ;
        vis1[u] = true ;
    }
    u = 0 ;
    for(int i = n2 - 1 ; i >= 0 ; i--){
        u += arr2[i] ;
        vis2[u] = true ;
    }
    u = 0 ;
    for(int i = n3 - 1 ; i >= 0 ; i--){
        u += arr3[i] ;
        vis3[u] = true ;
    }
    int ret = 0 ;
    for(int i = 10000000 ; i > 0 ; i--){
        if(vis1[i] +vis2[i] + vis3[i] == 3){
            ret = i ;
            break ;
        }
    }
    cout << ret << "\n" ;
}
