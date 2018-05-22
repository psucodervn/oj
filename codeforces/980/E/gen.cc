/*
  Task: E. The Number Games
  Site: codeforces
  Link: http://codeforces.com/contest/980/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n = atoi(argv[1]), k = atoi(argv[2]);
  srand(time(NULL));
  cout << n << " " << k << endl;
  // set<int> remains;
  // for (int i = 2; i <= n; ++i) remains.insert(i);
  // int cur = 1;
  // while (!remains.empty()) {
  //   auto it = remains.begin();
  //   int r = rand() % remains.size();
  //   while (r-- > 0) it++;
  //   cout << cur << " " << *it << endl;
  //   if (rand() % 2 == 1) cur = *it;
  //   remains.erase(it);
  // }

  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  // obtain a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (a.begin(), a.end(), std::default_random_engine(seed));
  for (int i = 1, cur = a[0]; i < n; ++i) {
    cout << cur << " " << a[i] << endl;
    if (rand() % 2 == 1) cur = a[i];
  }

  cout << endl;
  return 0;
}
