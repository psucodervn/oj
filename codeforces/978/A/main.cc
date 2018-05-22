/*
  Task: A. Remove Duplicates
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  set<int> s;
  vector<int> ans;
  for (int i = n - 1; i >= 0; --i) {
    if (s.count(a[i]) == 0) {
      ans.push_back(a[i]);
      s.insert(a[i]);
    }
  }
  cout << ans.size() << endl;
  for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
