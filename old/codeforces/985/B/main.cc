/*
  Task: B. Switches and Lamps
  Site: codeforces
  Link: http://codeforces.com/contest/985/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define dbg(x) { cerr << #x << " = " << x << endl; }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<int> sums(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) sums[j] += (s[i][j] - '0');
  }
  // dba(sums);
  for (int i = 0; i < n; ++i) {
    bool ans = true;
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '1' && sums[j] < 2) { ans = false; break; }
    }
    if (ans) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
