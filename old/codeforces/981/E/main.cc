/*
  Task: E. Addition on Segments
  Site: codeforces
  Link: http://codeforces.com/contest/981/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int n, qq;
vector<pair<int, int>> queries;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> qq;
  for (int i = 0; i < qq; ++i) {
    int a, b, x; cin >> a >> b >> x;
    queries.emplace_back(a, -x);
    queries.emplace_back(b, x);
  }
  sort(begin(queries), end(queries));

  vector<vector<long long>> cnt(2, vector<long long>(n + 1));
  int cur = 1, old = 0;
  cnt[old][0] = 1;
  vector<bool> ans(n + 1, false);
  for (auto q : queries) {
    int i, x;
    tie(i, x) = q; x = -x;
    // db(i, x, cur);
    if (x > 0) { // insert
      for (int a = 0, b = x; b <= n; ++a, ++b) {
        cnt[cur][b] = cnt[old][b] + cnt[old][a];
      }
      for (int b = 0; b < x; ++b) {
        cnt[cur][b] = cnt[old][b];
      }
    } else { // remove
      for (int b = 0; b < -x; ++b) {
        cnt[cur][b] = cnt[old][b];
      }
      for (int a = 0, b = -x; b <= n; ++a, ++b) {
        // db(cnt[old][b], cnt[cur][a]);
        cnt[cur][b] = cnt[old][b] - cnt[cur][a];
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (cnt[cur][i] != 0) ans[i] = true;
    }

    // dba(cnt[cur]);
    swap(cur, old);
  }

  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    if (ans[i]) res.push_back(i);
  }
  cout << res.size() << endl;
  for (auto x : res) cout << x << " ";
  cout << endl;
  return 0;
}
