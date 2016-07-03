#include<iostream>
using namespace std;
int x , y ;
bool isPal(string s){
    int j = s.length() ;
    for(int i = 0 ; i < j ; i++ , j--){
        if(s[i] != s[j-1]){
            x = i ;
            y = j - 1 ;
            return false ;
        }
    }
    return true ;
}
bool isPal2(string s){
    int j = s.length() ;
    for(int i = 0 ; i < j ; i++ , j--){
        if(s[i] != s[j-1]){
            return false ;
        }
    }
    return true ;
}

int main(){
    int T ;
    cin >> T ;
    while(T--){
        string s ;
        cin >> s ;
        int i , l = s.length() ;
        if(isPal(s) == false){
            string temp = s , temp2 = s ;
            temp.erase(temp.begin() + x) ;
            temp2.erase(temp2.begin() + y) ;
            if(isPal2(temp))    cout<<x<<endl;
            else if(isPal2(temp2))    cout<<y<<endl;
            else    cout<<-1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
