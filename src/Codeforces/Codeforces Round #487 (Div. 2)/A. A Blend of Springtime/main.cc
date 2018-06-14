/*
  Task: A. A Blend of Springtime
  Link: http://codeforces.com/contest/989/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;
#define ret(x) { cout << x << endl; return; }

void solve() {
  string s; cin >> s;
  int l = s.length();
  for (int i = 1; i < l - 1; ++i) {
    if (s[i] == '.' || s[i-1] == '.' || s[i+1] == '.') continue;
    if (s[i] != s[i-1] && s[i-1] != s[i+1] && s[i] != s[i+1]) ret("Yes");
  }
  ret("No");
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
