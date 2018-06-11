/*
  Task: D. Caesar's Legions
  Link: http://codeforces.com/problemset/problem/118/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

const int MOD = 1e8;
const int MAXN = 100;

void solve() {
  int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
  int dp[MAXN + 1][MAXN + 1][2];
  memset(dp, 0, sizeof(dp));
  // init
  for (int a = 1; a <= k1; ++a) dp[a][0][0] = 1;
  for (int b = 1; b <= k2; ++b) dp[0][b][1] = 1;
  // calc
  for (int a = 1; a <= n1; ++a) {
    for (int b = 1; b <= n2; ++b) {
      auto& res1 = dp[a][b][0];
      for (int k = 1; k <= min(a, k1); ++k) {
        res1 += dp[a - k][b][1];
        res1 %= MOD;
      }
      auto& res2 = dp[a][b][1];
      for (int k = 1; k <= min(b, k2); ++k) {
        res2 += dp[a][b - k][0];
        res2 %= MOD;
      }
    }
  }
  cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
