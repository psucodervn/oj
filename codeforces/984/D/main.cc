/*
  Task: D. XOR-pyramid
  Site: codeforces
  Link: http://codeforces.com/contest/984/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;
vector<vector<int>> pc;
vector<pair<int, int>> qs;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n; a = decltype(a)(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int q; cin >> q;
  qs = decltype(qs)(q);
  for (int i = 0; i < n; ++i) cin >> qs[i].first >> qs[i].second;
  sort(begin(qs), end(qs));

  n = 20;
  pc = decltype(pc)(n + 1);
  pc[0] = {1};
  for (int i = 1; i <= n; ++i) {
    pc[i] = vector<int>(i + 1, 1);
    for (int j = 1; j < i; ++j) pc[i][j] = (pc[i - 1][j - 1] + pc[i - 1][j]) % 2;
  }
  for (int i = 0; i <= n; ++i) {
    cout << i << ": ";
    for (int j = 0; j <= i; ++j) cout << pc[i][j] << " ";
    cout << endl;
  }


  return 0;
}

/*
1, 2, 4, 8, 16
1 x 2, 2 x 4, 4 x 8, 8x16
1x2x2x4, 2x4x4x8, 4x8x8x16
1x2x2x4x2x4x4x8, 2x4x4x8x4x8x8x16
1x2x2x4x2x4x4x8x2x4x4x8x4x8x8x16

1: 1
2: 4
4: 6
8: 4
16: 1

1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1

*/