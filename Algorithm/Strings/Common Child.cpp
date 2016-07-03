#include<bits/stdc++.h>
using namespace std ;
string s1 , s2 ;
int dp[5005][5005] ;
int lcs(int m, int n){
   if (m == 0 || n == 0)    return 0;
   if(dp[m][n] != -1)   return dp[m][n] ;
   if (s1[m-1] == s2[n-1])
        return dp[m][n] = 1 + lcs(m-1, n-1);
   else
        return dp[m][n] = max(lcs(m, n-1),
                              lcs(m-1, n));
}
int main(){
    while(cin>>s1>>s2){
        memset(dp,-1,sizeof(dp)) ;
        cout << lcs(s1.size() , s2.size()) << endl ;
    }
}
