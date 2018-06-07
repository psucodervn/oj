/*
  ID:   hungle.1
  LANG: C++14
  TASK: nocows
  LINK: http://train.usaco.org/usacoprob2?a=1bPlXy3vhlq&S=nocows
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

const int MOD = 9901;

void solve() {
  int N, K; cin >> N >> K;
  auto f = vector<vector<int>>(N + 1, vector<int>(K + 1));
  f[1][1] = 1;
  for (int n = 3; n <= N; n += 2) {
    for (int k = 1; k <= K; ++k) {
      auto& res = f[n][k];
      for (int l = 1; l <= n - 2; l += 2) {
        int r = n - l - 1;
        res = (res + f[l][k - 1] * f[r][k - 1]) % MOD;
        for (int kk = k - 2; kk >= 1; --kk) {
          res = (res + f[l][kk] * f[r][k - 1]) % MOD;
          res = (res + f[l][k - 1] * f[r][kk]) % MOD;
        }
      }
    }
  }
  cout << f[N][K] << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("nocows.in", "r", stdin);
  freopen("nocows.out", "w", stdout);
  solve();
  return 0;
}
