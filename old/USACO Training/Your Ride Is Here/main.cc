/*
  ID:   hungle.1
  LANG: C++14
  TASK: ride
  LINK: http://train.usaco.org/usacoprob2?a=kM4tl5pUOjq&S=ride
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
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  auto f = [&](string s) {
    int res = 1;
    for (auto c : s) {
      res = (res * (c - 'A' + 1)) % 47;
    }
    return res;
  };
  string s1, s2; cin >> s1 >> s2;
  cout << (f(s1) == f(s2) ? "GO" : "STAY") << endl;
  return 0;
}
