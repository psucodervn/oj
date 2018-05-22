/*
  Task: F. Mentors
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k; cin >> n >> k;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<int> c(n);
  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y; x--; y--;
    if (r[y] < r[x]) ++c[x];
    if (r[x] < r[y]) ++c[y];
  }
  vector<int> rr(r);
  sort(begin(rr), end(rr));
  for (int i = 0; i < n; ++i) {
    int f = lower_bound(begin(rr), end(rr), r[i]) - begin(rr);
    cout << (f - c[i]) << " ";
  }
  cout << endl;

  return 0;
}
