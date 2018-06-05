/*
  Task: C. The Smallest String Concatenation
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/632/C
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<string> s(n);
  for (auto& ss : s) cin >> ss;
  sort(begin(s), end(s), [](string a, string b) { return a + b < b + a; });
  string ans = "";
  for (auto ss : s) ans += ss;
  cout << ans << endl;
  return 0;
}
