#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

void troubleSort(vector<int>& a) {
  int N = a.size();
  bool done = false;
  while (!done) {
    done = true;
    for (int i = 0; i < N - 2; ++i) {
      if (a[i] > a[i + 2]) {
        done = false;
        swap(a[i], a[i + 2]);
      }
    }
  }
}

void gen(int t) {
  int N = rnd.next(1000, 1000); cout << N << endl;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    a[i] = rnd.next(1, 1000000000);
    cout << a[i] << (i < N - 1 ? " " : "\n");
  }
  troubleSort(a);
  int ans = -1;
  for (int k = 0; k < N - 1; ++k) {
    if (a[k] > a[k + 1]) {
      ans = k; break;
    }
  }
  cerr << "Case #" << t << ": ";
  if (ans < 0) cerr << "OK"; else cerr << ans;
  cerr << endl;
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T = 10; cout << T << endl;
  for (int t = 1; t <= T; ++t) {
    gen(t);
  }
  return 0;
}
