/*
  Task: F. AND Graph
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

const int MAXN = 22;
const int MAXA = (1 << MAXN);

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> av(m);
  bitset<MAXA * 2> have, used;
  for (int i = 0; i < m; ++i) {
    cin >> av[i];
    have[av[i]] = true;
  }

  int ans = 0;
  for (auto x : av) {
    if (!used[x]) {
      ++ans;
      queue<int> q;
      q.push(x); used[x] = true;
      // cerr << "new" << endl;
      while (!q.empty()) {
        auto u = q.front(); q.pop();
        // cerr << bitset<8>(u).to_string() << endl;
        if (u < (1 << n)) {
          auto uu = u + (1 << n);
          if (!used[uu]) { q.push(uu); };
          continue;
        }
        // check vertex (u, 1)
        auto uu = (2 << n) - 1 - u;
        if (have[uu] && !used[uu]) {
          used[uu] = true;
          q.push(uu);
        }
        // check others (ux, 2)
        for (int i = 0; i < n; ++i) {
          auto v = u | (1 << i);
          if (u != v && !used[v]) {
            used[v] = true;
            q.push(v);
          }
        }
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}
