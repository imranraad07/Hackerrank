#include <bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>

bool cmp(pii x , pii y){
    return x.first+x.second > y.first+y.second ;
}
int main(){
    int T ;
    cin >> T ;
    while(T--){
        int n , a ;
        vector< pii > v ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            v.push_back(make_pair(a,0)) ;
        }
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            v[i].second = a ;
        }
        sort(v.begin() , v.end() , cmp) ;
        int u = 0 , c = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(i&1) c += v[i].second ;
            else    u += v[i].first ;
        }
        if(u > c)   cout << "First";
        else if(u < c)  cout<<"Second";
        else    cout<<"Tie";
        cout<<endl;
    }
}
