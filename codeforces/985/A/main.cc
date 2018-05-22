/*
  Task: A. Chess Placing
  Site: codeforces
  Link: http://codeforces.com/contest/985/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

#define dbg(x) { cerr << #x << " = " << x << endl; }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> p(n / 2);
  for (int i = 0; i < n / 2; ++i) cin >> p[i];
  sort(begin(p), end(p));
  int res1 = 0;
  for (int i = 2; i <= n; i += 2) res1 += abs(i - p[i / 2 - 1]);
  int res2 = 0;
  for (int i = 1; i < n; i += 2) res2 += abs(i - p[i / 2]);
  cout << min(res1, res2) << endl;
  return 0;
}
