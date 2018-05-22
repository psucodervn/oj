/*
  Task: A. Wrong Subtraction
  Site: codeforces
  Link: http://codeforces.com/contest/977/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  long long n, k; cin >> n >> k;
  while (k-- > 0) {
    if (n % 10 == 0) n /= 10;
    else n -= 1;
  }
  cout << n << endl;
  return 0;
}
