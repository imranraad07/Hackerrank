#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    
    if(y2 > y1)    cout<<10000<<endl;
    else if(y2 < y1)    cout<<0<<endl;
    else if(m2 > m1)   cout<<500*(m2-m1)<<endl;
    else if(m2 < m1)    cout<<0<<endl;
    else if(d2 > d1)    cout<<15*(d2-d1)<<endl;
    else    cout<<0<<endl;
    
    return 0;
}
