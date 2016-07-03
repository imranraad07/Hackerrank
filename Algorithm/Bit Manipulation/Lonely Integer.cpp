#include <bits/stdc++.h>
using namespace std;
int main() {
    int res = 0 ;

    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        res = res^_a_item ;
    }

    cout << res;

    return 0;
}
