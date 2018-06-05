/*
  Task: C. Finite or not?
  Site: codeforces
  Link: http://codeforces.com/contest/984/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int n;

long long gcd(long long a, long long b) {
  long long r;
  while (b > 0){ 
    r = a % b; a = b; b = r;
  }
  return a;
}

bool solve(long long p, long long q, long long b) {
  long long g = gcd(p, q); p /= g; q /= g;
  if (q == 1) return true;
  g = gcd(q, b);
  while (g > 1) {
    g = gcd(q, g);
    q /= g;
  }
  return q <= 1;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  while (n-- > 0) {
    long long p, q, b; cin >> p >> q >> b;
    cout << (solve(p, q, b) ? "Finite" : "Infinite") << endl;
  }

  // for (int a = 1; a <= 10; ++a) {
  //   for (int b = 1; b <= 10; ++b) {
  //     cout << a << " " << b << " " << solve(a, b, 10) << " " << (double) a / b << endl;
  //   }
  // }

  return 0;
}
