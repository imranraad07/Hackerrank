#include <bits/stdc++.h>
using namespace std ;
#define ll long long

#define MAX 2000001
vector<int>v ;
int sieve[MAX] ;
void genPrimes(){
    v.push_back(2) ;
    long long i,j ;
    for(j=4;j<MAX;j+=2)               sieve[j] = 1 ;
    for(i=3;i<MAX;i+=2){
        if(sieve[i]==0){
            v.push_back(i) ;
            for(j=i*i;j<MAX;j+=i)               sieve[j] = 1 ;
        }
    }
}


int arr[45] ;
int f(int pos){
    if(pos <= 0) return 1 ;
    if(arr[pos])  return arr[pos] ;
    int ret = 0 ;
    if(pos -1 >= 0) ret += f(pos - 1)  ;
    if(pos -4 >= 0) ret += f(pos - 4)  ;
    return arr[pos] = ret ;
}

int main(){
    genPrimes() ;
    int T ;
    cin >> T ;
    while(T--){
        int n ;
        cin >> n ;
        cout << upper_bound(v.begin() , v.end() ,f(n) ) - v.begin() << endl;
    }
}
