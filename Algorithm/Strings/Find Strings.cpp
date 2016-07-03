#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const ll MAXN = 400050;
ll sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
string S ;
namespace SuffixArray{
    ll N, gap;
	bool sufCmp(ll i, ll j){
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}

	void buildSA(){
		N = S.length() ;
		REP(i, N) sa[i] = i, pos[i] = S[i];
		for (gap = 1;; gap *= 2){
			sort(sa, sa + N, sufCmp);
			REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
			REP(i, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
		}
	}

	void buildLCP(){
		for (ll i = 0, k = 0; i < N; ++i)
            if (pos[i] != N-1){
                for (ll j=sa[pos[i]+1];S[i+k]==S[j+k];) ++k;
                lcp[pos[i] + 1] = k;
                if (k)--k;
            }
	}
} // end namespace SuffixArray
ll N ;
string s1 ;
vector<int>v;
int arr2[200205] ;
int main(){
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int n ;
    cin >> n ;

    char c = 40 ;

    for(int i = 0 ; i < n ; i++){
        cin >> s1 ;
        S += s1 ;
        S += c ;
        c++ ;
    }

    N = S.length() ;


    SuffixArray::buildSA();
    SuffixArray::buildLCP();

    for(int i = N-1 ; i >= 0 ; i--){
        if(S[i] < 'a')  arr2[i] = i ;
        else    arr2[i] = arr2[i+1] ;
    }

    int lst = 0 ;
    for(int i = 0 ; i < N ; i++){
        if(S[sa[i]] < 'a'){
            v.push_back( 0 ) ;
        }
        else{
            v.push_back( v[i-1] + arr2[sa[i]] - sa[i] - lcp[i]) ;
        }
    }

//    cout<<S<<endl;
//    int z = 0 ;
//    for(int i = 0 ; i < N ; i++){
//        if(S[sa[i]] == '#') continue ;

    int q , r , u ;
    scanf("%d",&q) ;
    while(q--){
        scanf("%d",&r) ;
        //r-- ;
        if(r > v[N-1])    puts("INVALID");
        else{
            u = lower_bound(v.begin() , v.end() , r) - v.begin() ;
            r -= v[u-1] ;
            r += lcp[u] ;
            for(int i = sa[u] ; r ; i++){
                printf("%c",S[i]);
                r-- ;
            }
            puts("");
        }
    }
}
