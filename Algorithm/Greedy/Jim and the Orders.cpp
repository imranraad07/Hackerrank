#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector< pair<int,int> > v ;

int main() {
    int n , x , y ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y ;
        v.push_back(make_pair(x+y , i+1)) ;
    }
    sort(v.begin(),v.end()) ;
    for(int i = 0 ; i < n ; i++){
        cout<<v[i].second<<' ';
    }cout<<endl;
}
