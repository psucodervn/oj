/*
  Task: B. Two Cakes
  Site: codeforces
  Link: http://codeforces.com/contest/911/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, a, b; cin >> n >> a >> b;
  int best = 0;
  for (int nA = 1; nA <= n - 1; ++nA) {
    int nB = n - nA;
    int xA = a / nA, xB = b / nB;
    best = max(best, min(xA, xB));
  }
  cout << best << endl;
  return 0;
}
