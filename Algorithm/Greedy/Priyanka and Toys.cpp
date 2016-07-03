#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005] ;
int main() {
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    sort(arr , arr + n) ;
    int ret = 1 , w = arr[0] ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > w+4)    ret++, w=arr[i];
    }
    cout<<ret<<endl;
    return 0;
}
