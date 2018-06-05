/*
  Task: B. High School: Become Human
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

typedef long long ll;

ll power(ll a, ll n) {
  ll res = 1;
  for (int i = 0; i < n; ++i) res *= a;
  return res;
}

int solve(ll x, ll y) {
  if (x == y) return 0;
  if (x == 1) return -1;
  if (y == 1) return 1;
  if (max(x, y) <= 15) {
    ll ax = power(x, y);
    ll ay = power(y, x);
    return ax - ay;
  }
  return y - x;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  ll x, y; cin >> x >> y;
  int ans = solve(x, y);
  cout << (ans == 0 ? "=" : ans < 0 ? "<" : ">") << endl;
  return 0;
}
