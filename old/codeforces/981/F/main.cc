/*
  Task: F. Round Marriage
  Site: codeforces
  Link: http://codeforces.com/contest/981/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

typedef long long ll;
int n;
ll L;
vector<ll> a, b;

inline ll dist(int i, int j) {
  if (a[i] <= b[j])
    return min(b[j] - a[i], L - b[j] + a[i]);
  return min(a[i] - b[j], L - a[i] + b[j]);
}

ll calc(int shift) {
  if (shift <= -n || shift >= n) return L + 100;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + shift + n) % n;
    res = max(res, dist(i, j));
    // db(i, j, dist(i, j));
  }
  // db(res);
  return res;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> L;
  a = decltype(a)(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  b = decltype(b)(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(begin(a), end(a));
  sort(begin(b), end(b));

  auto startt = clock();
  auto endt = startt + CLOCKS_PER_SEC * 0.5;

  ll best = calc(0);
  int choose = 0;
  double step = n / 1000.0;
  for (int i = 0; i < 100; ++i) {
    auto k = step * i;
    auto res = calc(k);
    if (res < best) {
      best = res;
      choose = k;
    }
  }

  // db(choose, best);

  for (int shift = 0; shift < n && clock() < endt; ++shift) {
    best = min(best, calc(choose + shift));
    best = min(best, calc(choose - shift));
  }
  cout << best << endl;
  return 0;
}

/*
a[i] <= b[i]: max(b[i] - a[i], L - b[i] + a[i]) 
a[i] > b[i]:  max(a[i] - b[i], L - a[i] + b[i])
 */
