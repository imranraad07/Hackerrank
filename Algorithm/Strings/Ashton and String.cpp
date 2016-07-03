#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const ll MAXN = 300050;
ll sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
char S[MAXN];
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
		N = strlen(S);
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
                lcp[pos[i]+1] = k;
                if (k)--k;
            }
	}
} // end namespace SuffixArray
void reset(){
    memset(sa,0,sizeof(sa));
    memset(pos,0,sizeof(sa));
    memset(tmp,0,sizeof(sa));
    memset(lcp,0,sizeof(sa));
}
ll N ;
char s1[MAXN];
int main(){
//    freopen("input.txt" , "r" , stdin) ;
    ll l,i,st;
    ll T ;
    cin >> T ;
    while(T--){
        reset();
        ll k ;
        cin>>S>>k;

        N = strlen(S) ;

        SuffixArray::buildSA();
        SuffixArray::buildLCP();

        ll u = 0 , v , b , j , p ;
        u = 0 ;

        for(i=0;i<N;i++){
            v = N-sa[i] ;
            v = v*(v+1)/2 - lcp[i]*(lcp[i]+1)/2;
            if(k > v){
                k -= v;
                continue ;
            }
            for(j = lcp[i] + 1 ; j < N-sa[i] ; j++){
                if(j >= k)   break ;
                k -= j ;
            }
            cout<<S[sa[i]+k - 1]<<endl;
            break ;
        }
    }
}
