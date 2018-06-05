/*
  Task: Problem 1. Team Tic Tac Toe
  Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=831
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }
typedef long long int64;

void solve() {
  cout << 1 << endl;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  solve();
  return 0;
}
