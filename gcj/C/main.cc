#include <bits/stdc++.h>
using namespace std;

long long answer(int N, vector<long long>& W) {
  W[N + 1] = 1LL << 50; W[0] = 0;
  map<long long, int> wTolen;

  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    map<long long, int> temp;
    temp[W[i]] = 1;
    for (auto it : wTolen) {
      if (it.first <= W[i] * 6) {
        long long w = it.first + W[i];
        temp[w] = max(temp[w], it.second + 1);
      }
    }
    for (auto it : temp) {
      wTolen[it.first] = max(wTolen[it.first], temp[it.first]);
      ans = max(ans, (long long) wTolen[it.first]);
    }
  }
  return ans;
}

void solve(int testCase) {
  int N; cin >> N;
  vector<long long> W(N + 2);
  for (int i = 1; i <= N; ++i) cin >> W[i];
  cout << "Case #" << testCase << ": " << answer(N, W) << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}
