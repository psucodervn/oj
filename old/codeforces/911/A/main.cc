/*
  Task: A. Nearest Minimums
  Site: codeforces
  Link: http://codeforces.com/contest/911/problem/A
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
  vector<int> a(n);
  int minA = 2e9;
  for (auto& x : a) { cin >> x; minA = min(minA, x); }
  vector<int> mins;
  for (int i = 0; i < n; ++i) {
    if (a[i] == minA) mins.emplace_back(i);
  }
  int ans = 2e9;
  for (int i = 1, z = mins.size(); i < z; ++i) ans = min(ans, mins[i] - mins[i - 1]);
  cout << ans << endl;
  return 0;
}
