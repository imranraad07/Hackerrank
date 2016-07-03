#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a = 0 , b = 0 , c ;
    
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> c ;
           if(a_i == a_j)   a += c ;
           if(a_j == n - a_i - 1)   b += c ;
       }
    }
    cout << abs(a-b) << endl ;
    return 0;
}
