#include <bits/stdc++.h>
using namespace std;

int arr[1010];
int n;

void print(){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i]<<' ' ;
    }
    cout << endl;
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for (int i = 1 ; i < n ; i++){
       int j = i - 1 ;
       int u = arr[i] ;
       while (j >= 0 && arr[j] > u){
           arr[j+1] = arr[j] ;
           j-- ;
       }
       arr[j+1] = u ;
       print() ;
   }
}
