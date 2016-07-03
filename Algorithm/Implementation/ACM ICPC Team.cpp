#include <bits/stdc++.h>
using namespace std;

vector<string>v1 ;

int main(){
//    freopen("input.txt","r",stdin);
    int n;
    int m;
    cin >> n >> m;
    string s ;
    for(int i = 0;i < n;i++){
       cin >> s ;
       v1.push_back(s) ;
    }
    int u = 0 , v , mx = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            v = 0 ;
            for(int k = 0 ; k < m ; k++){
                if(v1[i][k] =='1' || v1[j][k] == '1') v++;
            }
            mx = max(mx,v) ;
        }
    }
    int c = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            v = 0 ;
            for(int k = 0 ; k < m ; k++){
                if(v1[i][k] =='1' || v1[j][k] == '1') v++;
            }
            if(v == mx){
                c++;
            }
        }
    }
    cout<<mx<<endl;
    cout<<c<<endl;
    return 0;
}
