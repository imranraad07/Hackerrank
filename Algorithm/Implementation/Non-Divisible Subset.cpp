#include <bits/stdc++.h>
using namespace std;
int arr[105] ;
int main() {
    int n , k ;
    while(cin >> n >> k){
        int i , a , j , ret = 0 , u ;
        for(i = 0 ; i < n ; i++){
            cin >> a ;
            arr[a%k]++ ;
        }
        for(i = 1 ; i <= k/2 ; i++){
            ret = ret + max(arr[i] , arr[k-i]) ;
        }

        u = k/2 ;
        if(u+u == k){
            ret -= arr[u] ;
            if(arr[u])  ret++ ;
        }
        if(ret && arr[0]) ret ++ ;
        if(k == 1)  ret = 1 ;
        cout<< ret << endl;
        memset(arr,0,sizeof(arr));
    }
}
