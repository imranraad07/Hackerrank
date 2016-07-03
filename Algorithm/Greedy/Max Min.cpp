#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
    sort(list , list + N) ;
    
    for(int i = N-1 ; i-K+1 >=0 ; i--){
        unfairness = min(unfairness , list[i]-list[i-K+1]) ;
        //cout<<list[i]<<' '<<list[i]-list[i-K]<<endl;
    }
    
    cout << unfairness << "\n";
    return 0;
}
