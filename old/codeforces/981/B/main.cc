/*
  Task: B. Businessmen Problems
  Site: codeforces
  Link: http://codeforces.com/contest/981/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n), x(n);
  map<int, int> ma, mb;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> x[i];
    ma[a[i]] = x[i];
  }
  int m; cin >> m;
  vector<int> b(m), y(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> y[i];
    mb[b[i]] = y[i];
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (mb[a[i]] == 0) {
      res += ma[a[i]];
    } else {
      if (ma[a[i]] >= mb[a[i]]) res += ma[a[i]];
    }
  }

  for (int i = 0; i < m; ++i) {
    if (ma[b[i]] == 0) {
      res += mb[b[i]];
    } else {
      if (mb[b[i]] > ma[b[i]]) res += mb[b[i]];
    }
  }

  cout << res << endl;
  return 0;
}
