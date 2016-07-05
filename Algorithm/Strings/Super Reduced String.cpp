#include <bits/stdc++.h>
using namespace std;
int main(){
    string s ;
    cin >> s ;
    stack < char > st ;
    for(auto i : s){
        if(st.size() == 0)  st.push(i) ;
        else{
            char c = st.top() ;
            if(c == i)  st.pop() ;
            else    st.push(i) ;
        }
    }
    if(st.size() == 0)  cout << "Empty String\n" ;
    else{
        s.clear() ;
        while(st.size()){
            s += st.top() ;
            st.pop() ;
        }
        reverse(s.begin() , s.end()) ;
        cout << s << "\n" ;
    }
}
