#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr1[1010];
int arr2[1010];
int n ;
int main() {
    cin >> n ;
    int x = 0 ;
    for(int i = 0 ; i < n ; i++)    cin >> arr1[i] , x^=arr1[i];
    for(int i = 0 ; i < n ; i++)    cin >> arr2[i] , x^=arr2[i];
    sort(arr1 , arr1 + n) ;
    sort(arr2 , arr2 + n) ;
    int ret = 0 , flag , u , i = 0 , j = 0 ;
    for(; i < n && j < n ;){
        if(arr1[i] == arr2[j]){
            ret++;
            i++;
            j++;
        }
        else if(arr1[i] > arr2[j]){
            j++;            
        }
        else{
            i++ ;
        }
    }    
    if(ret < n)    ret++;
    else    ret-- ;
    cout << ret << endl ;
    return 0;
}
