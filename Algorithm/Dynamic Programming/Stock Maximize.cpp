#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[50010];
ll b[50010];
int n;
int main(){
    int T,i;
    ll k;
    cin>>T;
    while(T--){
        memset(b,0,sizeof(b));
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        k = arr[n-1];
        for(i=n-2;i>=0;i--){
            b[i] = max(0LL,k-arr[i]);
            k = max(k,arr[i]);
        }
        ll ret = 0;
        for(i=0;i<n;i++){
            ret = ret + b[i];
        }
        cout<<ret<<endl;
    }
}
