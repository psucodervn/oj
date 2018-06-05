/*
  Task: A. Guest From the Past
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/625/A
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

long long solve(long long n, long long a, long long b, long long c) {
  if (a < b - c) {
    return n / a;
  }
  if (n < b) {
    return n / a;
  }
  long long res = (n - c) / (b - c);
  n -= res * (b - c);
  res += n / a;
  return res;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  long long n; cin >> n;
  long long a, b, c; cin >> a >> b >> c;
  cout << solve(n, a, b, c) << endl;
  return 0;
}
