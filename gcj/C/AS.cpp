#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;

#define prec setprecision

typedef long long ll;
typedef unsigned long long llu;
template<typename T> T gcd(T m, T n) {while(n) {T t=m%n; m=n;n=t;};return m;}
template<typename T> T exgcd(T a, T b, T& sa, T& ta) {T q, r, sb=0, tb=1, sc, tc; sa=1,ta=0; if(b) do q = a/b, r = a-q*b, a = b, b = r, sc = sa-q*sb, sa = sb, sb = sc, tc = ta-q*tb, ta = tb, tb = tc; while(b); return a; }
template<typename T> T mul_inv(T a, T b) { T t1 = a, t2 = b, t3; T v1 = 1, v2 = 0, v3; T x; while (t2 != 1) x = t1/t2, t3 = t1 - x*t2, v3 = v1 - x*v2, t1 = t2, t2 = t3, v1 = v2, v2 = v3; return (v2 + b) % b; }
template<typename T> T powmod(T a, T b, T MOD) {if (b < 0) return 0; T rv = 1; while (b) (b % 2) && (rv = (rv*a) % MOD), a = a*a%MOD, b /= 2; return rv;}

const int maxn = 1e5 + 7;

int n;
ll W[maxn];

template<int maxm>
class BIT{
	private:
		int m[maxm];
	public:
		void reset(){
			memset(m, 0, sizeof(m));
		}
		
		inline void update(int x, int v) {
			while(x < maxm) m[x]=max(m[x],v), x += x&-x;
		}
		inline int query(int x) {
			int r = 0;
			while(x>0) r = max(r, m[x]), x -= x&-x;
			return r;
		}
};

BIT<>

int solve() {
	cin >> n;
	map<ll, int> m;
	int r = 0;
	for(int i=1;i<=n;i++) {
		cin >> W[i];
		map<ll, int> m2;
		m2[W[i]] = 1;
		for(auto it: m) {
			if(it.first > W[i] * 6) break;
			ll w2 = it.first + W[i];
			m2[w2] = max(m2[w2], it.second + 1);
		}
		for(auto it: m2) {
			r = max(r, m[it.first] = max(m[it.first], m2[it.first]));
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
//	freopen("in.txt", "r", stdin)
	int t; cin >> t;
	for(int T=1;T<=t;T++) {
		printf("Case #%d: %d\n", T, solve());
	}
	return 0;
}