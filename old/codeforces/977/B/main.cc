/*
  Task: B. Two-gram
  Site: codeforces
  Link: http://codeforces.com/contest/977/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  string s; cin >> s;

  map<string, int> ss;
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    string temp = s.substr(i, 2);
    ss[temp]++;
    ans = max(ans, ss[temp]);
  }
  for (auto it : ss) {
    if (it.second == ans) {
      cout << it.first << endl;
      return 0;
    }
  }

  return 0;
}
