/*
  Task: D. Fair
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

const int MAXN = 1e5 + 100, MAXK = 111;
int n, m, k, s;
vector<int> a;
vector<vector<int>> adj;
int dist[MAXN][MAXK];

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> k >> s;

  auto contains = vector<vector<int>>(k, vector<int>());
  a = decltype(a)(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i]; a[i]--;
    contains[a[i]].push_back(i);
  }
  adj = decltype(adj)(n, vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(dist, -1, sizeof(dist));
  // loang goods
  for (int g = 0; g < k; ++g) {
    queue<int> q;
    for (auto x : contains[g]) { q.push(x); dist[x][g] = 0; }
    while (!q.empty()) {
      auto x = q.front(); q.pop();
      for (auto v : adj[x]) {
        if (dist[v][g] < 0) {
          dist[v][g] = dist[x][g] + 1;
          q.push(v);
        }
      }
    }
  }

  // calc
  for (int u = 0; u < n; ++u) {
    vector<int> temp;
    for (int g = 0; g < k; ++g) temp.push_back(dist[u][g]);
    sort(begin(temp), end(temp));
    int res = 0;
    for (int i = 0; i < s; ++i) res += temp[i];
    cout << res << " ";
  }
  cout << endl;

  return 0;
}
