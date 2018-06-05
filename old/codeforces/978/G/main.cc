/*
  Task: G. Petya's Exams
  Site: codeforces
  Link: http://codeforces.com/contest/978/problem/G
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<int> s(m), d(m), c(m);
  for (int i = 0; i < m; ++i) cin >> s[i] >> d[i] >> c[i];
  
  vector<int> ans;
  for (int day = 1; day <= n; ++day) {
    // cerr << "check at day " << day << endl;
    int minExam = -1, minExamDay = 1e9;
    bool doExam = false;
    for (int i = 0; i < m; ++i) {
      if (d[i] == day) {
        if (c[i] > 0) { cout << -1 << endl; return 0; }
        ans.push_back(m);
        doExam = true;
        break;
      }
      // cerr << i << " " << c[i] << " " << minExamDay << endl;
      if (c[i] > 0 && minExamDay > d[i] && s[i] <= day) {
        minExamDay = d[i];
        minExam = i;
      }
    }
    if (doExam) continue;
    // cerr << minExam << endl;
    if (minExam < 0) {
      ans.push_back(-1);
      continue;
    }
    if (c[minExam] > d[minExam] - day) {
      cout << -1; return 0;
    }
    ans.push_back(minExam);
    c[minExam]--;
  }
  for (auto x : ans) cout << x + 1 << " ";
  cout << endl;
  return 0;
}
