#include <bits/stdc++.h>
using namespace std ;
int arr[52] ;
set<int>s1 ;
int n ;
void f(int s, int r, int u) {
    if (r<0)  return ;
    if (r==0){
        s1.insert(u);
        return ;
    }
    for (int i = s ; i < n ; i ++){
        f(i+1,r-i,u^arr[i]);
    }
}

int main(){
    for(int i = 3 ; i <= 50 ; i++){
        s1.clear() ;
        n = i ;
        f(1,i,0) ;
        int ret = 0;
        while(s1.find(ret) != s1.end())  ret++ ;
        arr[i] = ret ;
        //cout << i << ' ' << ret << endl ;
    }

    int T ;
    cin >> T ;
    while(T--){
        int n , a , ret = 0 ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            ret = ret^arr[a] ;
        }
        if(ret) cout <<"ALICE"<<endl;
        else    cout <<"BOB"<<endl;
    }
}
