/*
ID: hungle.1
PROG: wormhole
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}

int N;
vector< pair<int, int> > holes;
vector<int> nextHole;
vector<int> p;

bool comp(pair<int, int> a, pair<int, int> b) {
	return (a.second == b.second ? a.first < b.first : a.second < b.second);
}

bool existLoop() {
	for (int start = 0; start < N; ++start) {
		int pos = start;
		for (int c = 0; c < N; ++c) {
			pos = nextHole[p[pos]];
			if (pos < 0) break;
		}
		if (pos >= 0) return true;
	}
	return false;
}

int getAnswer(int i) {
	if (i >= N) {
		return (existLoop() ? 1 : 0);
	}
	if (p[i] >= 0) return getAnswer(i + 1);

	int total = 0;
	for (int j = 0; j < N; ++j) {
		if (p[j] < 0 && i != j) {
			p[i] = j; p[j] = i;
			total += getAnswer(i + 1);
			p[i] = -1; p[j] = -1;
		}
	}
	return total;
}

void solve() {
	cin >> N;
	holes.reserve(N);
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		holes.push_back(make_pair(x, y));
	}
	sort(holes.begin(), holes.end(), comp);
	
	nextHole = vector<int>(N, -1);
	for (int i = 0; i < N - 1; ++i) {
		if (holes[i + 1].second == holes[i].second) nextHole[i] = i + 1;
	}

	p = vector<int>(N, -1);
	cout << getAnswer(0) << endl;
}
