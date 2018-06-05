/*
  Task: D. Xenia and Bit Operations
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/339/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  // input
  int n, m; cin >> n >> m;
  auto a = vector<vector<int>>(n + 1);
  for (int i = 0; i <= n; ++i) a[i] = vector<int>(1 << i);
  for (int i = 0; i < (1 << n); ++i) cin >> a[n][i];
  // preprocess
  for (int i = n - 1; i >= 0; --i) {
    for (int k = 0; k < (1 << i); ++k) {
      if ((n - i) & 1) a[i][k] = a[i + 1][k << 1] | a[i + 1][(k << 1) + 1];
      else a[i][k] = a[i + 1][k << 1] ^ a[i + 1][(k << 1) + 1];
    }
  }
  // query
  while (m-- > 0) {
    int p, b; cin >> p >> b; p--;
    a[n][p] = b;
    for (int i = n - 1; i >= 0; --i) {
      if (p & 1) --p;
      if ((n - i) & 1) a[i][p >> 1] = a[i + 1][p] | a[i + 1][p + 1];
      else a[i][p >> 1] = a[i + 1][p] ^ a[i + 1][p + 1];
      p >>= 1;
    }
    cout << a[0][0] << '\n';
  }
  return 0;
}
