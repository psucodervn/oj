/*
  Task: F. AND Graph
  Site: codeforces
  Link: http://codeforces.com/contest/987/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << ", "; err(++it, args...); }
#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dba(ar) { cerr << #ar << " = ["; for (auto x : ar) cerr << " " << x; cerr << "]" << endl; }

int n, m;
vector<int> a;

struct Trie {
  int nodes = 0;
  Trie* left;
  Trie* right;
} *root;

Trie* preprocess(Trie* node, int bit) {
  node = new Trie();
  node->nodes = 0;
  if (bit == 0) return node;
  node->left = preprocess(node->left, bit - 1);
  node->right = preprocess(node->right, bit - 1);
  return node;
}

inline int getBit(int val, int k) {
  return (val >> k) & 1;
}

void addToTree(Trie* node, int val, int bit) {
  db("+1", node->nodes, val, bit);
  node->nodes += 1;
  if (bit == 0) return;
  if (getBit(val, bit - 1)) addToTree(root->right, val, bit - 1);
  else addToTree(node->left, val, bit - 1);
}

void travel(Trie* node, int bit, string s, int val) {
  if (bit < 0) return;
  db(bit, s, node->nodes, val);
  travel(node->left, bit - 1, "left", 0);
  travel(node->right, bit - 1, "right", 0);
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  a = decltype(a)(m);
  bool hasZero = false;

  // preprocess
  root = preprocess(root, n);

  for (int i = 0; i < m; ++i) {
    cin >> a[i]; if (a[i] == 0) hasZero = true;
    addToTree(root, a[i], n);
  }
  if (hasZero) { cout << 1 << endl; return 0; }

  travel(root, n, "root", 0);

  return 0;
}
