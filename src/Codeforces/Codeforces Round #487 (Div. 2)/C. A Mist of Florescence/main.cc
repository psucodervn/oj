/*
  Task: C. A Mist of Florescence
  Link: http://codeforces.com/contest/989/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;
#define ret(x) { cout << x << endl; return; }

// int di = {-1, 0, 1, 0};
// int dj = {0, -1, 0, 1};

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n = 50, m = 50;
  vector<vector<char>> f(n, vector<char>(m));
  int curLine = 0;
  bool bA = false, bC = false;
  while (a > 1) {
    bA = true;
    for (int i = curLine; i < curLine + 3; ++i) {
      for (int j = 0; j < m; ++j) f[i][j] = 'B';
    }
    for (int j = 0; j < m && a > (b == 1 ? 0 : 1); j += 2, a--) f[curLine + 1][j] = 'A';
    curLine += 3;
  }
  if (a == 1) {
    if (bA) b--;
    while (b > 0) {
      for (int i = curLine; i < curLine + 3; ++i) {
        for (int j = 0; j < m; ++j) f[i][j] = 'A';
      }
      for (int j = 0; j < m && b > 0; j += 2, b--) f[curLine + 1][j] = 'B';
      curLine += 3;
    }
  }
  while (c > 1) {
    bC = true;
    for (int i = curLine; i < curLine + 3; ++i) {
      for (int j = 0; j < m; ++j) f[i][j] = 'D';
    }
    for (int j = 0; j < m && c > (d == 1 ? 0 : 1); j += 2, c--) f[curLine + 1][j] = 'C';
    curLine += 3;
  }
  if (c == 1) {
    if (bC) d--;
    while (d > 0) {
      for (int i = curLine; i < curLine + 3; ++i) {
        for (int j = 0; j < m; ++j) f[i][j] = 'C';
      }
      for (int j = 0; j < m && d > 0; j += 2, d--) f[curLine + 1][j] = 'D';
      curLine += 3;
    }
  }
  cout << curLine << " " << m << endl;
  for (int i = 0; i < curLine; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << f[i][j];
    }
    cout << endl;
  }
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
