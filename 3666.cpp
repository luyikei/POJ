#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <complex>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdlib>
#include <cctype>

#define REP(i,m,n) for(int i=m;i<(int)n;i++)
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n; i >= 0; i--)
#define rp(i,c) rep(i,(int)c.size())
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(u) (u).rbegin(),(u).rend()
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define v_delete(a,b) (a).erase(remove((a).begin(), (a).end(), b), (a).end())
#define v_unique(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define VV(T) vector<vector< T > >
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf=1<<28;
const double INF=1e10,EPS=1e-9;


template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}

template <class T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T> void input(T* a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }

int chmax(int& a,int b){
	if(b > a){
		a=b;
	}
	return a;
}
int chmin(int& a,int b){
	if(b < a){
		a=b;
	}
	return a;
}
int N;
long long int A[2010];
// dp[i][j] := i番目までの数列で、i番目をl[j]以下で新しい数列を作った時の最小コスト
long long int dp[2010][2010];
vi l;
int calc(long long int *a){
	rep(i,l.size()){
		dp[0][i]= llabs(a[0]-l[i]);
		if(i)
			dp[0][i] = min(dp[0][i],dp[0][i-1]);
	}
	REP(i,1,N){
		rep(j,l.size()){
			dp[i][j] = dp[i-1][j] + llabs(a[i] - l[j]);
			if(j)
				dp[i][j]=min(dp[i][j],dp[i][j-1]);
		}
	}
	return dp[N-1][static_cast<int>(l.size())-1];

}
int main()
{
	cin >> N;

	rep(i,N){
		int t;
		cin >> t;
		A[i]=t;
		l.pb(t);
	}
	l.erase(unique(all(l)),l.end());
	sort(all(l));
	int ans = calc(A);
	reverse(A,A+N);
	ans = min(ans,calc(A));
	cout << ans << endl;
	return 0;
}