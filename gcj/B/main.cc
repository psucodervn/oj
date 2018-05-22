#include <bits/stdc++.h>
using namespace std;

void solve(int testCase) {
  int N; cin >> N;
  map<int, bool> remains;
  vector<int> appears(N);
  for (int i = 0; i < N; ++i) remains[i] = true;
  for (int user = 1; user <= N; ++user) {
    int D; cin >> D;
    vector<int> flavors(D);
    for (int i = 0; i < D; ++i) {
      cin >> flavors[i];
      appears[flavors[i]]++;
    }
    int sell = -1, least = N + 10;
    for (int i = 0; i < D; ++i) {
      if (remains[flavors[i]]) {
        if (least > appears[flavors[i]]) {
          least = appears[flavors[i]];
          sell = flavors[i];
        }
      }
    }
    if (sell >= 0) remains[sell] = false;
    cout << sell << endl;
  }
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) solve(t);
  return 0;
}
