#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
ll bigmod ( ll a, ll p, ll m ){
    if(p==0)return 1 ;
    if(p&1){
        return ((a%m)*(bigmod(a,p-1,m)))%m ;
    }
    else{
        ll c = bigmod (a,p/2,m) ;
        return (c*c) % m ;
    }
}
int main(){
    ll n,T,i,a;
    cin>>T;
    while(T--){
        cin>>n;
        ll q = bigmod(2,n-1,MOD),r;
        cin>>a;
        r = a;
        for(i=1;i<n;i++){
            cin>>a;
            r = r|a;
        }
        r = r%MOD;
        q = (q*r)%MOD;
        cout<<q<<endl;
    }
}
