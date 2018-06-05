#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m, d; cin >> n >> m >> d;
  auto a = vector<vector<int>>(m, vector<int>(n));
  auto v = vector<int>();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      v.emplace_back(a[i][j]);
    }
  }


  auto L = v.size();
  sort(begin(v), end(v));
  for (int i = 1; i < L; ++i) {
    if ((v[i] - v[i - 1]) % d != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  long long sumSuffix = 0;
  for (int i = L - 1; i > 0; --i) sumSuffix += (v[i] - v[0]) / d;
  long long sumPrefix = 0, best = sumSuffix;
  for (int i = 1; i < L; ++i) {
    sumSuffix -= (v[i] - v[i - 1]) / d * (L - i);
    sumPrefix += (v[i] - v[i - 1]) / d * i;
    best = min(best, sumPrefix + sumSuffix);
  }
  cout << best << endl;

  return 0;
}
