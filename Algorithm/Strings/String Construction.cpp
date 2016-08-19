#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ;
    cin >> t ;
    while(t--){
        string s ;
        cin >> s ;
        set < char > st ; st.clear() ;
        for(auto i : s){
            st.insert(i) ;
        }
        cout << st.size() << "\n" ;
    }
}
