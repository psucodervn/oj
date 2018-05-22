/*
  Task: C. Kuro and Walking Route
  Site: codeforces
  Link: http://codeforces.com/contest/979/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> childs;
vector<bool> forbidden;

long long dfs(int u) {
  long long res = 1;
  for (int v : childs[u]) {
    if (!forbidden[v]) res += dfs(v);
  }
  return res;
};

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, x, y; cin >> n >> x >> y; x--; y--;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b; cin >> a >> b; a--; b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  vector<int> par(n, -1);
  childs = decltype(childs)(n);
  queue<int> q; q.push(x); par[x] = x;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (par[v] < 0) {
        par[v] = u;
        childs[u].emplace_back(v);
        q.push(v);
      }
    }
  }

  forbidden = decltype(forbidden)(n, false);
  for (int p = y; p != x; p = par[p]) forbidden[p] = true;

  long long cx = dfs(x);
  long long cy = dfs(y);
  // cerr << cx << " " << cy << endl;
  long long ans = (long long) n * (n - 1) - cx * cy;
  cout << ans << endl;

  return 0;
}
