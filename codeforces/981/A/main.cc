/*
  Task: A. Antipalindrome
  Site: codeforces
  Link: http://codeforces.com/contest/981/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

bool isPalin(string& s) {
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  string s; cin >> s;
  if (!isPalin(s)) {
    cout << s.length() << endl;
    return 0;
  }
  bool isSame = true;
  for (int i = s.length() - 1; i > 0; --i) {
    if (s[i] != s[i - 1]) { isSame = false; break; }
  }
  if (isSame) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = s.length() - 1; i >= 0; --i) {
    string ss = s.substr(0, i) + s.substr(i + 1);
    if (!isPalin(ss)) {
      cout << ss.length() << endl;
      return 0;
    }
  }
  return 0;
}
