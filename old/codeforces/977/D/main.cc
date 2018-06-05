/*
  Task: D. Divide by three, multiply by two
  Site: codeforces
  Link: http://codeforces.com/contest/977/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n; cin >> n;
  vector<unsigned long long> a(n);
  set<unsigned long long> remains;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    remains.insert(a[i]);
  }

  deque<unsigned long long> dq;
  dq.push_back(a[0]); remains.erase(a[0]);
  while (!remains.empty()) {
    auto v = dq.back();
    // cerr << v << ": ";
    if (remains.count(v * 2) > 0) {
      // cerr << v << " " << v * 2 << endl;
      dq.push_back(v * 2);
      remains.erase(v * 2);
      continue;
    }
    if (v % 3 == 0) {
      if (remains.count(v / 3) > 0) {
        // cerr << v << " " << v / 3 << endl;
        dq.push_back(v / 3);
        remains.erase(v / 3);
        continue;
      }
    }
    v = dq.front();
    // cerr << v << ": ";
    if (remains.count(v * 3) > 0) {
      // cerr << v * 3 << " " << v << endl;
      dq.push_front(v * 3);
      remains.erase(v * 3);
      continue;
    }
    if (v % 2 == 0) {
      if (remains.count(v / 2) > 0) {
        // cerr << v / 2 << " " << v << endl;
        dq.push_front(v / 2);
        remains.erase(v / 2);
        continue;
      }
    }
    assert(false);
  }

  while (!dq.empty()) {
    auto v = dq.front();
    cout << v << " ";
    dq.pop_front();
  }
  cout << endl;

  return 0;
}
