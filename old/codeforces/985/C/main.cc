/*
  Task: C. Liebig's Barrels
  Site: codeforces
  Link: http://codeforces.com/contest/985/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define dbg(x) { cerr << #x << " = " << x << endl; }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int n, k, l;
int nk;
vector<int> a;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n >> k >> l; nk = n * k;
  a = decltype(a)(n * k);
  for (int i = 0; i < nk; ++i) cin >> a[i];
  sort(begin(a), end(a));

  int r = a[0] + l;
  auto it = upper_bound(begin(a), end(a), r); --it;
  if (it - begin(a) + 1 < n) {
    cout << 0 << endl; return 0;
  }
  long long ans = a[0];
  int cur = 0; n--;
  while (cur + k < nk && a[cur + k] < *(it - n + 1)) {
    // dbg(cur + k); dbg(a[cur + k]); dbg(*(it - n + 1));
    ans += a[cur + k];
    cur += k;
    n--;
  }
  while (n-- > 0) {
    ans += *it; it--;
  }
  cout << ans << endl;
  return 0;
}
