/*
  ID:   hungle.1
  LANG: C++14
  TASK: concom
  LINK: http://train.usaco.org/usacoprob2?a=1bPlXy3vhlq&S=concom
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

void solve() {
  const int N = 100;
  int own[N + 1][N + 1];
  memset(own, 0, sizeof(own));
  set<int> ctls[N + 1];
  set<int> coms;
  int m; cin >> m;
  while (m-- > 0) {
    int i, j, p; cin >> i >> j >> p; // i--; j--;
    own[i][j] = p;
    coms.insert(i); coms.insert(j);
    if (p > 50) ctls[i].insert(j);
  }
  // calc
  for (auto c : coms) ctls[c].insert(c);
  for (int t = 0; t < N; ++t) {
    for (auto u : coms) {
      for (auto k : coms) {
        if (ctls[u].count(k)) continue;
        int curOwn = 0;
        for (auto v : ctls[u]) {
          curOwn += own[v][k];
        }
        if (curOwn > 50) {
          ctls[u].insert(k);
        }
      }
    }
  }
  // output
  for (auto u : coms) {
    for (auto v : ctls[u]) {
      if (u != v) cout << u << " " << v << endl;
    }
  }
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("concom.in", "r", stdin);
  freopen("concom.out", "w", stdout);
  solve();
  return 0;
}
