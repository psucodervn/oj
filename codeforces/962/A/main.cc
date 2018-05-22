/*
  Task: A. Equator
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/962/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int sum = accumulate(begin(a), end(a), 0);
  for (int i = 0, s = 0; i < n; ++i) {
    s += a[i];
    if (s + s >= sum) {
      cout << (i + 1) << endl;
      return 0;
    }
  }
  return 0;
}
