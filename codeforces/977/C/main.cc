/*
  Task: C. Less or Equal
  Site: codeforces
  Link: http://codeforces.com/contest/977/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  long long n, k; cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(begin(a), end(a));
  if (k == 0) {
    if (a[0] == 1) cout << -1 << endl;
    else cout << 1 << endl;
    return 0;
  }
  if (k == n) {
    cout << a[n - 1] << endl;
    return 0;
  }
  if (a[k - 1] == a[k]) { cout << -1 << endl; return 0; }
  cout << a[k - 1] << endl;

  return 0;
}
