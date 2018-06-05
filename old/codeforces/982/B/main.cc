/*
  Task: B. Bus of Characters
  Site: codeforces
  Link: http://codeforces.com/contest/982/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define dbg(x) { cerr << #x << " = " << x << endl; }
#define dba(ar) { cerr << #ar << " = {"; for (auto x : ar) cerr << " " << x; cerr << "}" << endl; }

void solve(int n, vector<int>& w, string& s) {
  priority_queue<pair<int, int>> empties, ones;
  for (int i = 0; i < n; ++i) empties.push({-w[i], i});
  for (auto c : s) {
    if (c == '0') {
      auto x = empties.top(); empties.pop();
      cout << x.second + 1 << " ";
      ones.push({ -x.first, x.second });
    } else {
      auto x = ones.top(); ones.pop();
      cout << x.second + 1 << " ";
    }
  }
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  string s; cin >> s;
  solve(n, w, s);
  return 0;
}
