/*
  Task: A. Infinity Gauntlet
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<string> s(n);
  map<string, bool> ma;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    ma[s[i]] = true;
  }

  vector<string> ss = {"purple", "green", "blue", "orange", "red", "yellow"};
  vector<string> sn = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

  vector<string> res;
  for (int i = 0; i < 6; ++i) {
    string a = ss[i];
    // db(a);
    if (!ma[a]) {
      res.push_back(sn[i]);
    }
  }
  cout << res.size() << endl;
  for (auto aaa : res) cout << aaa << endl;

  return 0;
}
