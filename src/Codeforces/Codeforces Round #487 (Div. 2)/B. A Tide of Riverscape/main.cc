/*
  Task: B. A Tide of Riverscape
  Link: http://codeforces.com/contest/989/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;
#define ret(x) { cout << x << endl; return; }

int n, p;
string s;

int output() {
  for (int i = 0; i < n; ++i) {
    if (s[i] != '.') cout << s[i];
    else cout << '0';
  }
  cout << endl;
  return 0;
}

int solve() {
  cin >> n >> p;
  cin >> s;
  for (int i = 0; i < n - p; ++i) {
    if (s[i] != '.') {
      if (s[i + p] != '.' && s[i + p] != s[i]) return output();
      if (s[i + p] == '.') {
        s[i + p] = (s[i] == '0' ? '1' : '0');
        return output();
      }
    } else { // s[i] == '.'
      if (s[i + p] != '.') {
        s[i] = (s[i + p] == '0' ? '1' : '0');
        return output();
      }
      if (s[i + p] == '.') {
        s[i] = '0'; s[i + p] = '1';
        return output();
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
