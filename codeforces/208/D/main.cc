/*
  Task: D. Prizes, Prizes, more Prizes
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/208/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  
  // input
  int n; cin >> n;
  vector<int64> p(n);
  for (auto& x : p) cin >> x;
  vector<int64> v(5);
  for (auto& x : v) cin >> x;

  // calc
  vector<int64> cnt(5);
  int64 remain = 0;
  for (auto x : p) {
    remain += x;
    for (int i = 4; i >= 0; --i) {
      cnt[i] += remain / v[i];
      remain %= v[i];
    }
  }

  // output
  for (auto x : cnt) cout << x << " ";
  cout << endl << remain << endl;
  return 0;
}
