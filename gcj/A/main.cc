#include <bits/stdc++.h>
using namespace std;

set<long long> values;

long long value(string s) {
  long long v = 0;
  for (int i = 0, l = s.length(); i < l; ++i) {
    v = (26 * v + (s[i] - 'A'));
  }
  return v;
}

long long dfsSet(int i, vector<set<int>>& c, int L, long long v) {
  if (i == L) {
    if (values.count(v) == 0) return v; else return -1;
  }
  for (auto a : c[i]) {
    auto newV = (26 * v + a);
    auto res = dfsSet(i + 1, c, L, newV);
    if (res >= 0) return res;
  }
  return -1;
}

string generateFromSet(vector<set<int>>& c, int L, int N) {
  auto res = dfsSet(0, c, L, 0);
  if (res < 0) return "-";
  string s = "";
  for (int i = 0; i < L; ++i) {
    s = (char)(res % 26 + 'A') + s;
    res /= 26;
  }
  return s;
}

string randomGenerate(vector<set<int>>& c, int L, int N) {
  srand(time(NULL));
  long long ans = -1;
  vector<vector<int>> cc(L);
  for (int i = 0; i < L; ++i) cc[i] = vector<int>(c[i].begin(), c[i].end());
  for (int r = 0; r < 1000; ++r) {
    long long v = 0;
    for (int i = 0; i < L; ++i) {
      int j = rand() % c[i].size();
      v = 26 * v + (cc[i][j]);
    }
    if (values.count(v) == 0) {
      ans = v;
      break;
    }
  }
  if (ans < 0) return "-";
  string s = "";
  for (int i = 0; i < L; ++i) {
    s = (char)(ans % 26 + 'A') + s;
    ans /= 26;
  }
  return s;
}

string answer(int N, int L, vector<string>& words) {
  if (L == 1) return "-";
  if (N == 1) return "-";

  values.clear();
  for (int i = 0; i < N; ++i) values.insert(value(words[i]));
  
  vector<set<int>> c(L);
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < N; ++j) c[i].insert(words[j][i] - 'A');
  }

  long long sum = 1;
  for (int i = 0; i < L; ++i) sum *= c[i].size();

  if (sum < N) return "-";

  if (sum < 10000) {
    return generateFromSet(c, L, N);
  } else {
    return randomGenerate(c, L, N);
  }

  return "-";
}

void solve(int testCase) {
  int N, L; cin >> N >> L;
  vector<string> words(N);
  for (int i = 0; i < N; ++i) cin >> words[i];
  cout << "Case #" << testCase << ": " << answer(N, L, words) << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}
