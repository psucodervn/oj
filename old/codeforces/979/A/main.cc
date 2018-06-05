/*
  Task: A. Pizza, Pizza, Pizza!!!
  Site: codeforces
  Link: http://codeforces.com/contest/979/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

#define long long long

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  long n; cin >> n;
  cout << (n == 0 ? 0 : (n % 2 == 0 ? n + 1 : (n + 1) / 2)) << endl;
  return 0;
}
