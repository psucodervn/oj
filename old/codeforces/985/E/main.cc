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
  sort(begin(a) + 1, end(a));
  // dba(a);
  vector<int> f(n + 1); f[0] = 1;
  deque<int> dq;
  dq.push_back(0);
  for (int i = 1; i <= n; ++i) {
    while (!dq.empty() && a[i] - a[dq.front() + 1] > d) dq.pop_front();
    if (!dq.empty() && i - dq.front() >= k) f[i] = 1; else f[i] = 0;
    if (f[i] == 1) dq.push_back(i);
  }
  // dba(f);
  return f[n] == 1;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k, d; cin >> n >> k >> d;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << (solve(a, n, k, d) ? "YES" : "NO") << endl;
  return 0;
}
