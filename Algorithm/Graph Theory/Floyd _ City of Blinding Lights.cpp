#include<bits/stdc++.h>
using namespace std ;

int cost[3002][3002] ;
int n , m ;

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            cost[i][j] = (1<<29) ;
        }
        cost[i][i] = 0 ;
    }
    int a , b , c  , sum = 0 ;
    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d",&a,&b);
        scanf("%d",&c);
        cost[a][b] = c ;
        sum += c ;
    }

    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ; j++){
                if(cost[i][k]+cost[k][j] < cost[i][j]){
                    cost[i][j] = cost[i][k]+cost[k][j] ;
                }
            }
        }
    }
    int k ;
    scanf("%d" , &k) ;
    while(k--){
        scanf("%d %d",&a,&b);
        if(cost[a][b] < sum)
            printf("%d\n" , cost[a][b]) ;
        //
        else    cout<<-1<<endl;
    }
}

