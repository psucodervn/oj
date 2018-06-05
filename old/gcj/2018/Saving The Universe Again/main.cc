#include <bits/stdc++.h>
using namespace std;

long long calc(string P) {
  long long res = 0, cur = 1;
  for (char c : P) {
    if (c == 'S') res += cur;
    else cur <<= 1;
  }
  return res;
}

int solve(long long D, string P) {
  int n = P.length();
  int step = 0;
  while (calc(P) > D) {
    int k = -1;
    for (int i = n - 1; i > 0; --i) {
      if (P[i] == 'S' && P[i - 1] == 'C') {
        k = i; break;
      }
    }
    if (k < 0) return -1;
    swap(P[k], P[k - 1]);
    ++step;
  }
  return step;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    long long D; string P;
    cin >> D >> P;
    int ans = solve(D, P);
    cout << "Case #" << t << ": ";
    if (ans < 0) cout << "IMPOSSIBLE"; else cout << ans;
    cout << endl;
  }
  return 0;
}
