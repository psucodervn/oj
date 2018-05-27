/*
  Task: D. Bookshelves
  Site: codeforces
  Link: http://codeforces.com/contest/981/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

typedef long long ll;
int n, k;
vector<ll> a;
int dp[55][55];

bool check(ll curVal, int curId, int remain) {
  if (curId >= n) {
    return remain == 0;
  } else if (remain == 0) {
    return false;
  }
  auto& res = dp[curId][remain];
  if (res >= 0) return res;

  res = 0;
  ll sum = 0;
  for (int i = curId; i < n; ++i) {
    sum += a[i];
    if ((sum & curVal) == curVal) {
      if (check(curVal, i + 1, remain - 1)) {
        res = 1; break;
      }
    }
  }
  return res;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  a = decltype(a)(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll curVal = 0;
  for (int i = 60; i >= 0; --i) {
    memset(dp, -1, sizeof(dp));
    if (check(curVal | (1ll << i), 0, k)) {
      curVal |= (1ll << i);
    }
  }
  cout << curVal << endl;
  return 0;
}
