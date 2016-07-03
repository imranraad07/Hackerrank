#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> arr2;
int sw ;
int partition(int s, int e) {
    int &pivot = arr[e] ;
    int u = s ;
    for (int i = s ; i < e ; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[u++]) ;
            sw++ ;
        }
    }
    swap(pivot, arr[u]) ;
    sw++ ;
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
    arr2 = arr ;
    sort(0, arr.size()-1) ;
    arr = arr2 ;

    //// insertion

    int k = 0 ;
    for (int i = 1 ; i < n ; i++){
       int j = i - 1 ;
       int u = arr[i] ;
       while (j >= 0 && arr[j] > u){
           arr[j+1] = arr[j] ;
           j-- ;
           k++ ;
       }
       arr[j+1] = u ;
   }

    cout << k - sw << endl ;
}
