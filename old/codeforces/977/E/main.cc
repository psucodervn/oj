/*
  Task: E. Cyclic Components
  Site: codeforces
  Link: http://codeforces.com/contest/977/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> labels;
vector<vector<int>> groups;

void dfs(int u) {
  for (auto v : adj[u]) {
    if (labels[v] < 0) {
      labels[v] = labels[u];
      groups[labels[u]].emplace_back(v);
      dfs(v);
    }
  }
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  adj = vector<vector<int>>(n, vector<int>());
  while (m-- > 0) {
    int u, v; cin >> v >> u; v--; u--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  labels = vector<int>(n, -1);
  int nGroups = -1;
  for (int i = 0; i < n; ++i) {
    if (labels[i] < 0) {
      labels[i] = ++nGroups;
      groups.emplace_back(vector<int>());
      groups[nGroups].emplace_back(i);
      dfs(i);
    }
  }

  int ans = 0;
  for (auto group : groups) {
    bool yes = true;
    // for (auto u : group) cerr << u + 1 << " ";
    // cerr << endl;
    for (auto u : group) {
      if (adj[u].size() != 2) {
        yes = false;
        break;
      }
    }
    if (yes) ++ans;
  }

  cout << ans << endl;

  return 0;
}
