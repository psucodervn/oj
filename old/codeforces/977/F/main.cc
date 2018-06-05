/*
  Task: F. Consecutive Subsequence
  Site: codeforces
  Link: http://codeforces.com/contest/977/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  a = vector<long long>(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<long long, int> mm;
  vector<int> d(n);
  int best = 0;
  for (int i = n - 1; i >= 0; --i) {
    mm[a[i]] = mm[a[i] + 1] + 1;
    best = max(best, mm[a[i]]);
  }

  cout << best << endl;
  for (int i = 0; i < n; ++i) {
    if (mm[a[i]] == best) {
      int cur = a[i];
      while (best > 0) {
        while (a[i] != cur) ++i;
        cout << (i + 1) << " ";
        cur += 1; best -= 1;
      }
      cout << endl;
      return 0;
    }
  }

  return 0;
}
