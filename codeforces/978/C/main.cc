/*
  Task: C. Letters
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> a, b;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  a = decltype(a)(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  b = decltype(b)(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  for (long long i = 0, d = 0, cur = 0; i < m; ++i) {
    b[i] -= cur;
    while (b[i] > a[d]) {
      b[i] -= a[d];
      cur += a[d];
      ++d;
    }
    cout << (d + 1) << " " << b[i] << endl;
  }
  return 0;
}
