#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][154][2][2][1390] ;
ll len ;
ll arr[20] ;
bool primes[1550] ;
void f2(ll k){
    len = 0 ;
    while(k){
        arr[len++] = k%10 ;
        k /= 10 ;
    }
    reverse(arr , arr + len) ;
}

ll f(ll dep , ll sum , bool flag , bool NotZero , ll sq){
    if(dep == len){
        return primes[sum] && primes[sq] ;
    }
    ll &ret = dp[len - dep][sum][flag][NotZero][sq] ;
    if(ret != -1 && flag) return ret ;
    ret=0 ;
    ll i , t = arr[dep] ;
    bool tflag , tNotZero ;
    for(i = 0 ; i < 10 ; i++){
		if(flag == false && i > arr[dep]) break ;
		tflag = flag || ( i < arr[dep] ) ;
		tNotZero = NotZero || ( i != 0 ) ;

        ret += f(dep + 1 , sum + i , tflag , tNotZero , sq + i*i) ;
    }
    return ret ;
}

bool isPrime(ll n){
    for(ll i = 2 ; i < n ; i++){
        if(n % i == 0)  return false ;
    }
    return true ;
}

int main(){
    for(ll i = 2 ; i < 1500 ; i++){
        primes[i] = isPrime(i) ;
    }
    memset(dp , -1 , sizeof(dp)) ;
    ll T , CASE = 0 , a , b , A , B ;
    scanf("%lld" , &T) ;
    while(T--){
        scanf("%lld" , &A) ;
        scanf("%lld" , &B) ;
        ll ans ;
        f2(A-1) ;
        a = f(0 , 0 , 0 , 0 , 0 ) ;
        f2(B) ;
        b = f(0 , 0 , 0 , 0 , 0 ) ;
        ans = b - a ;
        printf("%lld\n" , ans) ;
    }
}
