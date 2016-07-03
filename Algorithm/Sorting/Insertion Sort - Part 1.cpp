#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  ar) {
int sz =ar.size();
    int k =sz-1,j;
    int e ;
    for(int i=1;i<sz;i++){
        e = ar[sz-1-i];
    //    cout<<e<<endl;
        if(ar[sz-1-i]>ar[k]){
            swap(ar[sz-1-i],ar[k]);
        }
        else break;
           for(j=0;j<sz;j++){
               if(j==sz-1-i){
                   cout<<e;
               }
               else cout<<ar[j];
               cout<<' ';
           }
           cout<<endl; 
           
           k--;
    }
    
    for(int i=0;i<sz;i++){
        cout<<ar[i]<<' ';
    }cout<<endl;
}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    insertionSort(_ar);
    return 0;
}
