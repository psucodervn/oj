/*
  Task: E. Swapping Characters
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/903/E
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int k, n;
vector<string> s;

int check(int i, int j) {
  for (int h = k - 1; h > 0; --h) {
    int diff = 0;
    bitset<26> b;
    bool identical = true;
    for (int x = 0; x < n; ++x) {
      if (s[h][x] != s[0][x]) {
        ++diff;
        if (diff > 5) return diff;
      }
      if (b[s[h][x] - 'a']) { identical = false; }
      b[s[h][x] - 'a'] = true;
    }
    if (!(diff == 0 || diff == 2)) return diff;
    if (diff == 0 && identical) return 5;
  }
  return 0;
}

void solve() {
  if (k == 1) {
    swap(s[0][0], s[0][1]);
    cout << s[0] << endl;
    return;
  }
  vector<int> cnt(26);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[0][i] - 'a'];
  }
  for (int i = 1; i < k; ++i) {
    vector<int> c(26);
    for (int j = 0; j < n; ++j) ++c[s[i][j] - 'a'];
    for (int j = 0; j < 26; ++j) {
      if (cnt[j] != c[j]) {
        cout << -1 << endl;
        return;
      }
    }
  }
  for (int j = 1; j < n; ++j) {
    int d = 0;
    for (int i = 0; i < n - 1; ++i) {
      swap(s[0][i], s[0][j]);
      d = check(i, j);
      if (d == 0 || d == 2) {
        cout << s[0] << endl;
        return;
      }
      swap(s[0][i], s[0][j]);
      if (d > 5) break;
    }
  }
  cout << -1 << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> k >> n;
  s = decltype(s)(k);
  for (auto& x : s) cin >> x;
  solve();
  return 0;
}
