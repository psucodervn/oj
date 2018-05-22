#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > genFactors(int n) {
	vector< pair<int, int> > v;
	for (int d = 2; d <= n; ++d) {
		if (n % d == 0) {
			int k = 0;
			while (n % d == 0) {
				++k; n /= d;
			}
			v.push_back(make_pair(d, k));
		}
	}
	return v;
}

long long modPow(long long base, long long p) {
	long long ans = 1, exp = p % (MOD - 1);
	while (exp > 0) {
		if (exp & 1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return ans;
}


int n, m;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> m;
	
	
	return 0;
}