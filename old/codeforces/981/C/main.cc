/*
  Task: C. Useful Decomposition
  Site: codeforces
  Link: http://codeforces.com/contest/981/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> degs(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b; cin >> a >> b; a--; b--;
    degs[a]++; degs[b]++;
  }

  vector<pair<int, int>> d;
  for (int i = 0; i < n; ++i) {
    d.push_back({ degs[i], i });
  }
  sort(begin(d), end(d));

  if (d[n - 1].first <= 2) {
    cout << "Yes" << endl << 1 << endl;
    cout << d[0].second + 1 << " " << d[1].second + 1 << endl;
    return 0;
  }

  if (d[n - 2].first > 2) {
    cout << "No" << endl;
    return 0;
  }

  vector<int> ans;
  cout << "Yes" << endl;
  for (int i = 0; i < n; ++i) {
    if (i != d[n - 1].second && degs[i] == 1) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << d[n - 1].second + 1 << " " << x + 1 << endl;
  }

  return 0;
}
