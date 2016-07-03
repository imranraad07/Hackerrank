#include <bits/stdc++.h>
using namespace std;

vector < pair < string , int > > v[105] ;
int main() {
    int n , a ;
    cin >> n ;
    string s ;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> s ;
        v[a].push_back( make_pair (s , i) ) ;
    }
    int k = 0 ;
    s.clear() ;
    for(int i = 0 ; i<100 ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            if(v[i][j].second*2 < n ){
                if(s == "") s += "-";
                else    s += " -" ;
            }
            else{
                if(s == "") s += v[i][j].first ;
                else    s += " " + v[i][j].first ;
            }
        }
    }
    cout << s << endl ;
    return 0;
}