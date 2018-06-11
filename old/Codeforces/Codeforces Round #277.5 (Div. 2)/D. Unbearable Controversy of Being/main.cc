/*
  Task: D. Unbearable Controversy of Being
  Link: http://codeforces.com/problemset/problem/489/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

int64 calcFromU(int u, vector<vector<int>>& adj) {
  map<int, int> cnt;
  for (auto v : adj[u]) {
    for (auto k : adj[v]) {
      if (k != u) ++cnt[k];
    }
  }
  int64 res = 0;
  for (auto p : cnt) {
    int64 c = p.second;
    res += c * (c - 1);
  }
  return res >> 1;
}

void solve() {
  // input
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  while (m-- > 0) {
    int u, v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
  }
  // calc
  int64 ans = 0;
  for (int u = 0; u < n; ++u) {
    ans += calcFromU(u, adj);
  }
  // output
  cout << ans << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
