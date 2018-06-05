/*
  Task: E. Bus Video System
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, w; cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int up = w, down = 0;
  for (int i = n - 1; i >= 0; --i) {
    up = min(w, up - a[i]);
    down = max(0, down - a[i]);
  }
  cout << max(up - down + 1, 0) << endl;

  return 0;
}
