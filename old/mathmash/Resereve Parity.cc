#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int MAX = 90;

void dfs(int i, int pre) {
  if (i == 10) { ans += (MAX - pre + 1) >> 1; return; }
  for (int v = pre + 1; v <= MAX + i - 10; v += 2) dfs(i + 1, v);
}

int main() {
  dfs(1, 0);
  cout << ans << endl;
}
