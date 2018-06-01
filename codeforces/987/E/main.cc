/*
  Task: E. Petr and Permutations
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

const int MAXN = 1e6 + 1000;
typedef long long ll;
int bit[MAXN];
vector<int> a;

ll sum(int idx) {
  ll res = 0;
  while (idx > 0) {
    res += bit[idx];
    idx -= idx & (-idx);
  }
  return res;
}

void update(int n, int idx, int val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & (-idx);
  }
}

ll getInvCount(int n) {
  ll res = 0;
  memset(bit, 0, sizeof(bit));
  for (int i = n - 1; i >= 0; --i) {
    res += sum(a[i] - 1);
    update(n, a[i], 1);
  }

  return res;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  a = decltype(a)(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll res = getInvCount(n);
  cout << (res % 2 == n % 2 ? "Petr" : "Um_nik") << endl;
  return 0;
}
