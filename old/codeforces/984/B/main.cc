/*
  Task: B. Minesweeper
  Site: codeforces
  Link: http://codeforces.com/contest/984/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  bool ans = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') continue;
      if (s[i][j] == '.') s[i][j] = '0';
      int sum = 0;
      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          if (di == 0 && dj == 0) continue;
          if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= m) continue;
          if (s[i + di][j + dj] == '*') ++sum;
        }
      }
      int d = s[i][j] - '0';
      // cerr << i << " " << j << " " << d << " " << sum << endl;
      if (d != sum) { ans = false; break; }
    }
    if (!ans) break;
  }

  cout << (ans ? "YES" : "NO") << endl;

  return 0;
}
