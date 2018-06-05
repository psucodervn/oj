#include <bits/stdc++.h>

using namespace std;

map<long long, long long> cnt;
priority_queue<long long> remains;

pair<long long, long long> solve(long long N, long long K) {
	cnt.clear();
	remains = priority_queue<long long>();
	
	remains.push(N); cnt[N] = 1;
	long long k = 0;
	while (k < K) {
		long long nxt = remains.top(); remains.pop();
		long long cnxt = cnt[nxt];
		long long mi = (nxt - 1) / 2;
		long long ma = (nxt - 1) - mi;
		if (k + cnxt >= K) return make_pair(ma, mi);
		
		if (!cnt[mi]) remains.push(mi);
		if (!cnt[ma]) remains.push(ma);
		cnt[mi] += cnxt; cnt[ma] += cnxt; cnt[nxt] = 0;
		k += cnxt;
	}
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long N, K; cin >> N >> K;
		auto p = solve(N, K);
		cout << "Case #" << t << ": " << p.first << " " << p.second << endl;
	}
	
	return 0;
}