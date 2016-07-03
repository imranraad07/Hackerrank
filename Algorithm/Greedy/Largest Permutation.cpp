#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[100005] ;
priority_queue < pair<int,int>  > pq ;
pair<int,int> tmp ;
int main() {
    int n , k ;
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
        pq.push(make_pair(arr[i] , i) ) ;
    }
    for(int i = 0 ; i < n ; i++){
        if(k == 0)  break ;
        do{
            tmp = pq.top() ; 
            pq.pop() ;
        }while(tmp.second < i);
        if(arr[i] < tmp.first){
            pq.push( make_pair(arr[i] , tmp.second) ) ;
            swap(arr[i] , arr[tmp.second]) ;
            k-- ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << ' ' ;
    }cout << endl;
}
