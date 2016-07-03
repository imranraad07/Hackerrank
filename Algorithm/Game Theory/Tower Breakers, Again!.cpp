#include <stdbool.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std ;
int a[1000010];
int GrundyNumbers(int x){
    if(a[x]!=-1) return a[x];
    bool table[25];
    memset(table,0,sizeof(table));
    int i,c,k=sqrt(x);
    for(i=1;i<=k;i++){

        if(x%i)     continue ;

        if(i == 1){
            table[0]=true;
        }
        else{
            c = x/i ;
            if(c%2) table[GrundyNumbers(i)]=true;
            else    table[0]=true;
            if(i%2) table[GrundyNumbers(c)]=true;
            else    table[0]=true;
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

