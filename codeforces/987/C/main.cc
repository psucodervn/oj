/*
  Task: C. Three displays
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/C
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
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  vector<int> dp(n);
  int INF = 1e9;
  for (int i = 0; i < n; ++i) {
    dp[i] = INF;
    for (int j = i + 1; j < n; ++j) {
      if (s[i] < s[j]) {
        dp[i] = min(dp[i], c[i] + c[j]);
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] < s[j]) {
        ans = min(ans, c[i] + dp[j]);
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
