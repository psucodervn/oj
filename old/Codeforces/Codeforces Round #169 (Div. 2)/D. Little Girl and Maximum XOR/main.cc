/*
  Task: D. Little Girl and Maximum XOR
  Link: https://codeforces.com/problemset/problem/276/D
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

int64 calc(int64 l, int64 r, int64 cur, int bit) {
  int bl = (l >> bit) & 1;
  int br = (r >> bit) & 1;
  if (bl < br) {
    cur |= (1LL << bit);
  } else if (bl > br) {
    cur |= (1LL << bit);
  } else if (bl == 1 && br == 1) {
    auto newR = r & ~(1LL << bit);
    if (newR >= l) {
      cur |= (1LL << bit);
      r = newR;
    }
  } else {
    auto newL = ((l >> bit) + 1) << bit;
    if (newL <= r) {
      cur |= (1LL << bit);
      l = newL;
    } 
  }
  if (bit == 0) return cur;
  return calc(l, r, cur, bit - 1);
}

void solve() {
  int64 L, R; cin >> L >> R;
  cout << calc(L, R, 0, 60) << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
