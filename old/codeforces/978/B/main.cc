/*
  Task: B. File Name
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  string s; cin >> s; s = "_" + s + "_";
  int ans = 0;
  for (int i = 0, cur = 0; i < s.length(); ++i) {
    if (s[i] == 'x') ++cur;
    else {
      ans += max(0, cur - 2);
      cur = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
