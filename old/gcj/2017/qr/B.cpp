#include <bits/stdc++.h>

using namespace std;

string solve(long long N) {
	string s = "";
	while (N > 0) {
		s = (char) (N % 10 + '0') + s;
		N /= 10;
	}
	
	int k = 0;
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] < s[i - 1]) { k = i; break; }
	}
	if (k == 0) return s;
	int d = k - 1;
	while (d > 0 && s[d - 1] == s[k - 1]) --d;
	
	s[d]--;
	for (int i = d + 1; i < s.length(); ++i) s[i] = '9';
	if (s[0] == '0') s = s.substr(1);
	
	return s;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long N; cin >> N;
		cout << "Case #" << t << ": " << solve(N) << endl;
	}
	
	return 0;
}