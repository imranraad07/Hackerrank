#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int partition(int s, int e) {
    int &pivot = arr[e] ;
    int u = s ;
    for (int i = s ; i < e ; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[u++]) ;
        }
    }
    swap(pivot, arr[u]) ;

    for(auto i : arr)  cout << i << ' ' ;
    cout << endl ;

    return u ;
}

void sort(int s, int e) {
    if (s == e) return ;
    int i = partition(s, e) ;
    if (i != s) sort(s, i-1) ;
    if (i != e) sort(i+1, e) ;
}

int main() {
    int n , a ;
    cin >> n ;
    for (int i = 0 ; i <n ; i++) {
        cin >> a ;
        arr.push_back(a) ;
    }
    if (arr.size() == 0) return 0 ;
    sort(0, arr.size()-1) ;
}
