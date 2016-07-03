#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[1010] ;
int main(){
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
    }
    int ret = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i]%2){
            arr[i] ++ ;
            arr[i+1]++;
            ret += 2 ;
        }
    }
    bool flag = false ;
    for(int i = 1 ; i <= n ; i++){
        if(arr[i]%2){
            flag = true ;
        }
    }
    if(flag)    cout<<"NO"<<endl;
    else    cout<<ret<<endl;
}
