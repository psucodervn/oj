#include <bits/stdc++.h>

using namespace std;

void solve(int K) {
	int sz = 1, cnt = 0;
	while (sz < K) sz <<= 1;
	cout << sz << " ";
	if (K == sz) { cout << 0 << endl; return; }
	while (K > 0) {
		sz >>= 1; cnt++;
		if (K >= sz) K -= sz;
	}
	cout << cnt << endl;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int K; cin >> K; solve(K);
//	for (int K = 1; K <= 1000; ++K) solve(K);
	
	return 0;
}