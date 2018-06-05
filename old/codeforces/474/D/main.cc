/*
  Task: D. Flowers
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/474/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

typedef long long int64;
const int MOD = 1e9 + 7, N = 1e5;
vector<int64> dp, sum;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T, K; cin >> T >> K;

  // preprocess
  dp = decltype(dp)(N + 1, 1);
  for (int i = K; i <= N; ++i) {
    dp[i] = dp[i - 1] + dp[i - K];
    dp[i] %= MOD;
  }

  sum = decltype(sum)(N + 1);
  for (int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + dp[i];

  // query
  while (T-- > 0) {
    int a, b; cin >> a >> b;
    int ans = (sum[b] - sum[a - 1]) % MOD;
    cout << ans << '\n';
  }
  return 0;
}
