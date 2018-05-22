/*
  Task: A. Row
  Site: codeforces
  Link: http://codeforces.com/contest/982/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(int n, string& s) {
  s = "0" + s + "0";
  return s.find("000") == string::npos && s.find("11") == string::npos;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  string s; cin >> s;
  cout << (solve(n, s) ? "Yes" : "No") << endl;
  return 0;
}
