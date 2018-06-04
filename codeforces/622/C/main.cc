/*
  Task: C. Not Equal on a Segment
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/622/C
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  // preprocess
  vector<int> p(n); p[0] = -1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) p[i] = i - 1;
    else p[i] = p[i - 1];
  }

  // query
  while (m-- > 0) {
    int l, r, x; cin >> l >> r >> x; l--; r--;
    if (a[r] != x) { cout << r + 1 << endl; }
    else {
      if (p[r] >= l) cout << p[r] + 1 << endl;
      else cout << -1 << endl;
    }
  }
  return 0;
}
