/*
  Task: E. Pencils and Boxes
  Site: codeforces
  Link: http://codeforces.com/contest/985/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define db(x) { cerr << #x << " = " << x << endl; }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

bool solve(vector<int>& a, int n, int k, int d) {
  sort(begin(a), end(a));
  vector<int> f(n, -1), g(n, -1);
  for (int i = 0; i < n; ++i) {
  }
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k, d; cin >> n >> k >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << (solve(a, n, k, d) ? "YES" : "NO") << endl;
  return 0;
}
