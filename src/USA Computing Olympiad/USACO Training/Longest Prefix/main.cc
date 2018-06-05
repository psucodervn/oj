
/*
  ID:   hungle.1
  LANG: C++14
  Task: prefix
  Link: http://train.usaco.org/usacoprob2?a=1bPlXy3vhlq&S=prefix
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

void solve() {
  
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);
  solve();
  return 0;
}
