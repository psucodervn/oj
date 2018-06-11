/*
  Task: D. Common Divisors
  Link: http://codeforces.com/problemset/problem/182/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

inline int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b; a = b; b = r;
  }
  return a;
}

bool isDivisor(string& s, string pre) {
  int l = s.length(), n = pre.length();
  for (int i = 0; i < l; i += n) {
    if (s.substr(i, n) != pre) {
      return false;
    }
  }
  return true;
}

void solve() {
  string s1, s2; cin >> s1 >> s2;
  int l1 = s1.length(), l2 = s2.length();
  int g = gcd(l1, l2);
  string s = s1.substr(0, g);
  if (!isDivisor(s1, s) || !isDivisor(s2, s)) {
    cout << 0 << endl;
    return;
  }
  int ans = 1;
  for (int i = 1; i * 2 <= g; ++i) {
    if (g % i == 0) {
      if (isDivisor(s, s.substr(0, i))) ++ans;
    }
  }
  cout << ans << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
