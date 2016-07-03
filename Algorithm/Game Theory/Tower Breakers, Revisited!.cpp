#include <stdbool.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std ;
int a[1000010];
int GrundyNumbers(int x){
    if(a[x]!=-1) return a[x];
    bool table[25];
    memset(table,0,sizeof(table));
    int i,k=sqrt(x);
    for(i=1;i<=k;i++){

        if(x%i)     continue ;

        if(i == 1){
            table[GrundyNumbers(i)]=true;
        }
        else{
            table[GrundyNumbers(i)]=true;
            table[GrundyNumbers(x/i)]=true;
        }
    }
    k=0;
    while(table[k]==1)   k++;
    a[x]=k;
    return k;
}

int main(){
    memset(a,-1,sizeof(a));
    a[0]=0;
    a[1]=0;
//    int y = 0 ;
//    for(int i = 2 ; i <= 1000000 ; i++){
//        GrundyNumbers(i) ;
//        y = max(y , GrundyNumbers(i)) ;
//        cout << i << ' ' << GrundyNumbers(i) << endl;
//    }
//    cout<<y<<endl;

    int T ;
    cin >> T ;
    while(T--){
        int n , a , r = 0 ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            r = r^GrundyNumbers(a) ;
        }
        if(r)   cout<<1<<endl;
        else    cout<<2<<endl;
    }
}

