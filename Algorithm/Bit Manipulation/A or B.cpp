#include <bits/stdc++.h>
using namespace std ;
#define ll long long

string media(char c){
    if(c == '0')    return "0000" ;
    if(c == '1')    return "0001" ;
    if(c == '2')    return "0010" ;
    if(c == '3')    return "0011" ;
    if(c == '4')    return "0100" ;
    if(c == '5')    return "0101" ;
    if(c == '6')    return "0110" ;
    if(c == '7')    return "0111" ;
    if(c == '8')    return "1000" ;
    if(c == '9')    return "1001" ;
    if(c == 'A')    return "1010" ;
    if(c == 'B')    return "1011" ;
    if(c == 'C')    return "1100" ;
    if(c == 'D')    return "1101" ;
    if(c == 'E')    return "1110" ;
    return "1111" ;
}

string media2(string c){
    if(c == "0000")    return "0" ;
    if(c == "0001")    return "1" ;
    if(c == "0010")    return "2" ;
    if(c == "0011")    return "3" ;
    if(c == "0100")    return "4" ;
    if(c == "0101")    return "5" ;
    if(c == "0110")    return "6" ;
    if(c == "0111")    return "7" ;
    if(c == "1000")    return "8" ;
    if(c == "1001")    return "9" ;
    if(c == "1010")    return "A" ;
    if(c == "1011")    return "B" ;
    if(c == "1100")    return "C" ;
    if(c == "1101")    return "D" ;
    if(c == "1110")    return "E" ;
    return "F" ;
}

string hex2bin(string s){
    string ret ; ret.clear() ;
    for(auto i : s){
        ret += media(i) ;
    }
    return ret ;
}

string myor(string a , string b){
    string ret ; ret.clear() ;
    int sz1 = a.size() , sz2 = b.size() ;
    for(int i = sz1 -1 , j = sz2 - 1 ; ; i-- , j--){
        if(i >= 0 && j >= 0){
            if(a[i] == '0' && b[i] == '0')  ret += "0" ;
            else  ret += "1" ;
        }
        else if(i >= 0){
            ret += a[i] ;
        }
        else if(j >= 0){
            ret += b[j] ;
        }
        else    break ;
    }
    reverse(ret.begin() , ret.end()) ;
    return ret ;
}

string bin2hex(string s){
    string ret , a ; ret.clear() ;
    int l = s.length() ;
    for(int i = 0 ; i < l ; i+=4){
        a.clear() ;
        a += s[i] ;
        a += s[i+1] ;
        a += s[i+2] ;
        a += s[i+3] ;
        a = media2(a) ;
        if(ret.size() == 0 && a == "0") continue ;
        ret += a ;
    }
    if(ret.size() == 0) ret = "0" ;
    return ret ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q , k ;
    cin >> q ;
    while(q--){
        cin >> k ;
        string a , b , c ;
        string aa , bb , cc ;
        cin >> aa >> bb >> cc ;
        a = hex2bin(aa) ;
        b = hex2bin(bb) ;
        c = hex2bin(cc) ;
        string u = myor(a , b) ;
        if(c.length() > u.length()){
            int x = c.length() - u.length() ;
            string tmp ; tmp.clear() ;
            for(int i = 0 ; i < x ; i++){
                tmp += "0" ;
            }
            u = tmp + u ;
        }
        else if(c.length() < u.length()){
            int x = u.length() - c.length() ;
            string tmp ; tmp.clear() ;
            for(int i = 0 ; i < x ; i++){
                tmp += "0" ;
            }
            c = tmp + c ;
        }
        if(a.length() < u.length()){
            int x = u.length() - a.length() ;
            string tmp ; tmp.clear() ;
            for(int i = 0 ; i < x ; i++){
                tmp += "0" ;
            }
            a = tmp + a ;
        }
        if(b.length() < u.length()){
            int x = u.length() - b.length() ;
            string tmp ; tmp.clear() ;
            for(int i = 0 ; i < x ; i++){
                tmp += "0" ;
            }
            b = tmp + b ;
        }

        int e = k ;
        for(int i = u.length() - 1 ; i >= 0 ; i--){
            if(u[i] != c[i]){
                if(u[i] == '1'){
                    if(a[i] == '1' && b[i] == '1'){ /// a , b 1
                        a[i] = '0' ; e-- ;
                        b[i] = '0' ; e-- ;
                    }
                    else if(a[i] == '1'){ /// a 1
                        a[i] = '0' ; e-- ;
                    }
                    else{ /// b 1
                        b[i] = '0' ; e-- ;
                    }
                }
                else{/// a , b 2tai 0 ;
                    b[i] = '1' ; e-- ;
                }
            }
        }
        if(e < 0 ){
            cout << "-1" << "\n" ;
        }
        else{
            for(int i = 0 ; i < a.length() ; i++){
                if(e >= 2 && a[i] == '1' && b[i] == '0'){
                    a[i] = '0' ;
                    b[i] = '1' ;
                    e -= 2 ;
                }
                else if(e >= 1 && b[i] == '1' && a[i] == '1'){
                    a[i] = '0' ;
                    e -= 1 ;
                }
            }

            cout << bin2hex(a) << "\n" ;
            cout << bin2hex(b) << "\n" ;
        }
    }
}
