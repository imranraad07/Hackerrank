#include <bits/stdc++.h>
using namespace std;

void partition(vector <int> &arr) {
    if(arr.size() <= 1) return;
    int start = 0 ;
    int pivot = arr[start];
    vector<int> smaller, larger;
    for(auto i : arr){
        if(i < pivot) smaller.push_back(i);
        else if(i > pivot) larger.push_back(i);
    }
    partition(smaller) ;
    partition(larger) ;
    int ctr = start ;
    for(auto i : smaller) arr[ctr++] = i ;
    arr[ctr++] = pivot;
    for(auto i : larger) arr[ctr++] = i ;
    for(auto i : arr){
        cout << i << ' ' ;
    }cout << endl;
}

int main() {
    int n ;
    cin >> n ;
    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }
    partition(arr) ;
}
