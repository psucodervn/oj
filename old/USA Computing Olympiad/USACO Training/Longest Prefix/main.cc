/*
  ID:   hungle.1
  LANG: C++14
  TASK: prefix
  LINK: http://train.usaco.org/usacoprob2?a=1bPlXy3vhlq&S=prefix
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

set<string> P;
string S;

void solve() {
  do {
    string p; cin >> p;
    if (p == ".") break;
    P.insert(p);
  } while (true);
  string s;
  while (cin >> s) {
    S += s;
  }

  int n = S.length(), ans = 0;
  vector<bool> f(n + 1); f[0] = true;
  for (int i = 0; i < n; ++i) {
    for (auto p : P) {
      int k = i - p.length() + 1;
      if (k < 0) continue;
      if (f[k] && S.substr(k, p.length()) == p) {
        f[i + 1] = true;
        ans = i + 1;
        break;
      }
    }
  }
  cout << ans << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);
  solve();
  return 0;
}
