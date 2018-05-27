/*
  Task: D. Inversion Counting
  Site: codeforces
  Link: http://codeforces.com/contest/911/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int n;
vector<int> a;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  a = decltype(a)(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) ++res;
    }
  }

  int m; cin >> m;
  while (m-- > 0) {
    int l, r; cin >> l >> r; l--; r--;
    res += (r - l + 1) / 2;
    cout << (res % 2 == 0 ? "even" : "odd") << endl;
  }
  return 0;
}
