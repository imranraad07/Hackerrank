#include <bits/stdc++.h>
using namespace std ;
#define ff first
#define ss second
#define mp make_pair
int arr2[256] ;
int arr[256] ;
int arr3[256] ;

bool check(int x){
    for(int i = x - 1 ; i >= 'a' ; i--){
        if(arr2[i]) return false ;
    }
    return true ;
}
int main(){
//    freopen("input.txt" , "r" , stdin) ;
    string s ;
    cin >> s ;
    int l = s.length() ;
    for(int i = 0 ; i < l ; i++){
        arr2[s[i]]++ ;
    }
    for(int i = 'a' ; i <= 'z' ; i++){
        arr2[i] = arr2[i]/2 ;
        arr3[i] = arr2[i] ;
    }
    string ret ; ret.clear() ;
    priority_queue < pair<int,int> ,
        std::vector<pair<int,int>>, std::greater<pair<int,int>> > skip;

    pair < int , int > tmp ;
    while(skip.size())  skip.pop() ;
    int u = 0 , k = 0 ,j = 0 , lst = - 1 ;
    for(int i = l-1 ; i>= 0 ; i-- ){
        if(arr3[s[i]] <= arr[s[i]]){
            continue ;
        }
        if(check(s[i]) || arr2[s[i]] <= 0){
            bool clip = false ;
            while(!skip.empty()){
                tmp = skip.top() ;
                skip.pop() ;
                if(tmp.ff < s[i] && -tmp.ss < lst &&
                   arr3[tmp.ff] > arr[tmp.ff]){
                    arr[tmp.ff]++ ;
                    arr2[tmp.ff]++ ;
                    ret += tmp.ff ;
                    lst = -tmp.ss;
                }
                else if(tmp.ff == s[i] && -tmp.ss < lst &&
                   arr3[tmp.ff] > arr[tmp.ff]){
                    arr[tmp.ff]++ ;
                    arr2[tmp.ff]++ ;
                    ret += tmp.ff ;
                    lst = -tmp.ss;
                    clip = true ;
                    break ;
                }
            }
            if(clip){
                arr2[s[i]]-- ;
                skip.push( mp(s[i] , -i ) ) ;
                continue ;
            }
            ret += s[i] ;
            arr[s[i]]++ ;
            arr2[s[i]]-- ;
            lst = i ;
        }
        else{
            arr2[s[i]]-- ;
            skip.push( mp(s[i] , -i ) ) ;
        }
    }
    reverse(s.begin(),s.end()) ;
    cout << ret << endl;
}
