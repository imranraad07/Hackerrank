#include <bits/stdc++.h>
using namespace std;
int arr[105] ;
bool isWinning(int pos){
    if(pos <= 1)    return false ;
    if(arr[pos] != -1)  return arr[pos] ;
    int moves[] = {2,3,5} ;
    for(int i = 0 ; i < 3 ; i++){
        if(isWinning(pos-moves[i]) == false)    return arr[pos] = true ;
    }
    return arr[pos] = false ;
}

int main(){
    memset(arr,-1,sizeof(arr)) ;
    int T , n ;
    cin >> T ;
    while(T--){
        cin >> n ;
        if(isWinning(n))    cout<<"First"<<endl;
        else    cout<<"Second"<<endl;
    }
}
