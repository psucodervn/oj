/*
  Task: E. Post Lamps
  Link: http://codeforces.com/contest/990/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;
#define ret(x) { cout << x << endl; return; }

void solve() {
  // input
  int64 n, m, k; cin >> n >> m >> k;
  vector<int> s(m);
  for (int i = 0; i < m; ++i) cin >> s[i];
  vector<int> a(k + 1);
  for (int i = 1; i <= k; ++i) cin >> a[i];
  // calc
  sort(begin(s), end(s));
  if (s[0] == 0) ret(-1);
  int maxD = -1;
  for (int i = 1, d = 1; i <= m; ++i) {
    if (i == m) { maxD = max(maxD, d); break; }
    if (s[i] == s[i - 1] + 1) ++d;
    else { maxD = max(maxD, d); d = 1; }
  }
  db(maxD);
  if (k <= maxD) ret(-1);
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
