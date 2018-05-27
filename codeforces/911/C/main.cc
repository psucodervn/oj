/*
  Task: C. Three Garlands
  Site: codeforces
  Link: http://codeforces.com/contest/911/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

bool solve(int k1, int k2, int k3) {
  vector<int> a = {k1, k2, k3};
  sort(begin(a), end(a));
  if (a[0] == 1) return true;
  if (a[0] == 2) {
    if (a[1] == 2) return true;
    if (a[1] == 4 && a[2] == 4) return true;
  }
  if (a[0] == 3) {
    if (a[1] == 3 && a[2] == 3) return true;
  }
  return false;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int k1, k2, k3; cin >> k1 >> k2 >> k3;
  cout << (solve(k1, k2, k3) ? "YES" : "NO") << endl;
  return 0;
}
