/*
  Task: D. Almost Arithmetic Progression
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> b;

int isValid(int firstValue, int step) {
  long long cur = firstValue;
  int res = 0;
  for (int i = 0; i < n; ++i, cur += step) {
    if (abs(b[i] - cur) > 1) return n + 1;
    if (b[i] != cur) ++res;
  }
  // cerr << firstValue << " " << step << " " << res << endl;
  return res;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  b = decltype(b)(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long maxD = b[1] - b[0], minD = b[1] - b[0];
  for (int i = 1; i < n; ++i) {
    minD = min(minD, b[i] - b[i - 1]);
    maxD = max(maxD, b[i] - b[i - 1]);
  }
  if (maxD - minD > 4) { cout << -1 << endl; return 0; }
  int best = n + 1;
  for (long long d = minD; d <= maxD; ++d) {
    for (long long v = b[0] - 1; v <= b[0] + 1; ++v) {
      best = min(best, isValid(v, d));
    }
  }
  cout << (best > n ? -1 : best) << endl;
  return 0;
}
