#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100005] ;
ll sum[100005] ;
int main(){
    int T ;
    scanf("%d" , &T) ;
    while(T--){
        int n ;
        scanf("%d" , &n) ;
        for(int i = 0 ; i < n ; i++){
            scanf("%lld" , &arr[i]) ;
        }
        sort(arr,arr+n);
        ll s = 1 , p = 0 , k ;
            sum[n-1] = arr[n-1] ;
            for(int i = n-2 ; i >= 0 ; i--){
                sum[i] = sum[i+1] + arr[i] ;
            }
            for(int i = 0 ; i < n ; i++){
                k = sum[i]*s ;
                if( (s+1)*sum[i+1] >= k ){
                    s++ ;
                }
                else{
                    p += arr[i]*s ;
                }
            }
            printf("%lld\n" , p) ;
        memset(sum,0,sizeof(sum)) ;
    }
}
