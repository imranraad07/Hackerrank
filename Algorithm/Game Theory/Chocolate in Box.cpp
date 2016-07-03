#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
    int n,a,ret = 0 , g = 0 ;
    cin>>n;
    while(n--){
        cin>>a;
        v.push_back(a) ;
        g = g^a;
    }
//    cout << g << endl;
    for(int i = 0 ; i < v.size() ; i++){
        if( (g^v[i]) < v[i] ) ret++;
    }
    cout<<ret<<endl;
}
