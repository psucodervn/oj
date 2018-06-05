#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> V;
map<int, int> m[2];

int solve() {
  m[0] = m[1] = map<int, int>();
  for (int i = 0; i < N; ++i) m[i & 1][V[i]]++;
  sort(begin(V), end(V));
  for (int i = 0; i < N; ++i) {
    if (m[i & 1][V[i]] == 0) return i;
    m[i & 1][V[i]]--;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N;
    V = vector<int>(N);
    for (int i = 0; i < N; ++i) cin >> V[i];
    int ans = solve();
    cout << "Case #" << t << ": ";
    if (ans < 0) cout << "OK"; else cout << ans;
    cout << endl;
  }
  return 0;
}
