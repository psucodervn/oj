/*
  Task: A. Paper Airplanes
  Site: codeforces
  Link: http://codeforces.com/problemset/problem/965/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  long long k, n, s, p; cin >> k >> n >> s >> p;
  long long sheets = ((n - 1) / s + 1) * k;
  long long packs = (sheets - 1) / p + 1;
  cout << packs << endl;

  return 0;
}
