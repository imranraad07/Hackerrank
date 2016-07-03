#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 200050;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
char S[MAXN];
namespace SuffixArray{
    int N, gap;
	bool sufCmp(int i, int j){
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
		for (int i = 0, k = 0; i < N; ++i)
            if (pos[i] != N-1){
                for (int j=sa[pos[i]+1];S[i+k]==S[j+k];) ++k;
                lcp[pos[i]] = k;
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
int N , M ;
char s1[MAXN],s2[MAXN];
int arr[MAXN] ;
int main(){
    int l,i,st;
    int T ;
    cin >> T ;
    while(T--){
        reset();
        cin>>s1>>s2;
        strcat(s1,"a");
        strcat(s2,"a");

        N = strlen(s1) ;
        M = strlen(s2) ;

        strcpy(S,s1);
        strcat(S,"#");
        strcat(S,s2);


        SuffixArray::buildSA();
        SuffixArray::buildLCP();
        l=-1;
        st=-1;
        for(i=0;i<=N+M;i++){
            arr[sa[i]] = i ;
        }

//        cout<<S<<endl;
//        for(i=0;i<=N+M;i++){
//            cout<<S[i]<<' '<<arr[i]<<endl;
//        }cout<<endl;

        string ret ; ret.clear() ;

        int i = 0 , j = 0 ;

        while(i < N && j < M){
            if(arr[i] < arr[N+j+1]){
                ret += s1[i];
                i++ ;
            }
            else{
                ret += s2[j];
                j++ ;
            }
            if(i == N -1){
                while(j < M - 1)  ret += s2[j++];
                break;
            }
            if(j == M - 1){
                while(i < N - 1)  ret += s1[i++];
                break ;
            }
        }
        cout<<ret<<endl;
    }
}
