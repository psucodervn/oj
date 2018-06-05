/*
  Task: D. Sand Fortress
  Site: codeforces
  Link: http://codeforces.com/contest/985/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define dbg(x) { cerr << #x << " = " << x << endl; }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long ll;

ll n, H;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> H;
  if (H >= (ll) 2e9) {
    ll res = sqrt(n * 2);
    if (res * (res + 1) / 2 < n) res++;
    cout << res << endl;
    return 0;
  }
  if (H * (H + 1) / 2 >= n) {
    ll res = sqrt(n * 2);
    if (res * (res + 1) / 2 < n) res++;
    cout << res << endl;
    return 0;
  }
  // n += H * (H + 1) / 2;
  dbg(n);
  ll need = n - H * (H + 1) / 2 - H;
  dbg(need);
  ll low = 0, high = 2e9, best = 2e9 + 10;
  while (low <= high) {
    ll col = (low + high) / 2;
    ll sum = (col / 2) * (col / 2 + 1);
    if (col % 2 == 1) sum += (col / 2 + 1);
    sum += col * H;
    dbg(col); dbg(sum);
    if (sum >= need) { best = min(best, col); high = col - 1; }
    else { low = col + 1; }
  }
  cout << (H + 1 + best) << endl;
  return 0;
}
