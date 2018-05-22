/*
  Task: A. Game
  Site: codeforces
  Link: http://codeforces.com/contest/984/problem/0
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(begin(a), end(a));
  if (n % 2 == 1) cout << a[n / 2];
  else cout << a[n / 2 - 1];
  cout << endl;

  return 0;
}
