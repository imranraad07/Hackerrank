#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>v ;
int main() {
    int a , n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> a ;
        v.push_back(a) ;
    }
    sort(v.begin(),v.end());
    cout<<v[n/2]<<endl;
    return 0;
}
