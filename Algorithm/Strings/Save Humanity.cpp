/***
Extended KMP: finds longest common prefix from current position
*/
#include <bits/stdc++.h>
using namespace std ;

char s1[100002] ;
char s2[100002] ;
int arr[2][100010] ;
int f[2][100010] ;

void ExPreKMP(int flag){
    int m = strlen(s2) ;
    int i, a = 0 , p = 0 , j = -1 ;
    f[flag][0] = 0 ;
    for (i = 1 ; i < m ; i++, j--){
        if(j < 0 || i + f[flag][i - a] >= p){
            if (j < 0){
                j = 0 ;
                p = i ;
            }
            while (p < m && s2[p] == s2[j]){
                p++ ;
                j++;
            }
            f[flag][i] = j ;
            a = i ;
        }
        else{
            f[flag][i] = f[flag][i - a];
        }
    }
}

void GetExtend(int flag){
    ExPreKMP(flag);
    int n = strlen(s1) ;
    int m = strlen(s2) ;
    int i, a = 0 , p = 0 , j = -1;
    for (i = 0; i < n; i++ , j--){
        if (j < 0 || i + f[flag][i - a] >= p){
            if (j < 0){
                j = 0 ;
                p = i ;
            }
            while (p < n && j < m && s1[p] == s2[j]){
                j++ ;
                p++ ;
            }
            arr[flag][i] = j ;
            a = i ;
        }
        else arr[flag][i] = f[flag][i - a];
    }
//    for(i = 0 ; i < n ; i++){
//        cout << arr[flag][i] << ' ';
//    }cout << endl;
}

int main(){
    int T ;
    cin >> T ;
    while(T--){
        cin >> s1 >> s2 ;
        GetExtend(0) ;
        int n = strlen(s1) ;
        int m = strlen(s2) ;
        reverse(s1 , s1 + n) ;
        reverse(s2 , s2 + m) ;
        GetExtend(1) ;
//        reverse(s1 , s1 + n) ;
//        cout << s1 << endl;
        int ret = 0 ;
        reverse(arr[1] , arr[1] + n) ;
        vector < int > v ;
        for(int i = 0 , j = m-1 ; i <= n-m ; i++ , j++){
            if(arr[0][i] + arr[1][j] + 1 >= m){
                v.push_back(i) ;
//                cout << s1[i] << ' ' << s1[j] << ' ' << i << ' ' << j << endl ;
                ret++ ;
            }
        }
//        cout << ret << endl;
        if(ret){
            for(int i = 0 ; i < ret ; i++){
                cout << v[i] << ' ' ;
            }cout << endl ;
        }
        else{
            cout << "No Match!" << endl;
        }

        memset(arr , 0 , sizeof(arr)) ;
        memset(f , 0 , sizeof(f)) ;
    }
    return 0;
}
