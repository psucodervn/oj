/*
  Task: D. A Shade of Moonlight
  Link: http://codeforces.com/contest/989/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;
#define ret(x) { cout << x << endl; return; }

int N, L, Wmax;
vector<int> x, v;

void solve() {
  cin >> N >> L >> Wmax;
  x = decltype(x)(N);
  v = decltype(v)(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> v[i];
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
