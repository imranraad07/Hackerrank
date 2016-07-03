#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,a;
    cin >> n;
    vector<int>v,temp;v.clear();
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    while(v.size()){
        cout<<v.size()<<endl;
        temp.clear() ;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i]-v[0] > 0){
                temp.push_back(v[i]-v[0]) ;
            }
        }
        v = temp;
    }
    return 0;
}
