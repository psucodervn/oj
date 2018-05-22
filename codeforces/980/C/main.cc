/*
  Task: C. Posterized
  Site: codeforces
  Link: http://codeforces.com/contest/980/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, k; cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  vector<bool> b(256, false);
  vector<int> a(256, -1);
  for (int i = 0; i < n; ++i) {
    if (b[p[i]]) continue;
    if (!b[p[i]] && a[p[i]] >= 0) { b[p[i]] = true; continue; }
    int left = p[i];
    while (left > 0 && p[i] - left + 2 <= k && !b[left - 1]) left -= 1;
    // cerr << left << " " << p[i] << endl;
    for (int j = left; j <= p[i]; ++j) { a[j] = left; b[j] = true; }
    for (int j = p[i] + 1; j < 256 && j - left + 1 <= k; ++j) { a[j] = left; }
  }

  for (int i = 0; i < n; ++i) cout << a[p[i]] << " \n"[i == n - 1];
  // cout << endl;

  return 0;
}
