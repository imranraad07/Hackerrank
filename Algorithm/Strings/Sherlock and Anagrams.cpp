#include <bits/stdc++.h>
using namespace std;
vector <string> v ;
int main(){
    int T ;
    cin >> T ;
    while(T--){
        v.clear() ;
        string s ;
        cin >> s ;
        int i , l = s.length() , j ;
        string temp ;
        for(int i = 0 ; i < l ; i++){
            temp.clear() ;
            for(int j = i ; j < l ; j++){
                temp += s[j] ;
                //cout<<temp<<endl;
                sort(temp.begin(),temp.end()) ;
                v.push_back(temp);
            }
        }
//        sort(v.begin(),v.end()) ;
        int sz = v.size() , ret =  0 ;
        for(int i = 0 ; i < sz ; i++){
            for(int j = i+1 ; j < sz ; j++){
                if(v[i] == v[j])    ret++ ;
            }
        }
        cout << ret <<endl;
    }
}
