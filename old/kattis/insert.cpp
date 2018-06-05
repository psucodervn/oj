#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *left, *right;
	Node (int val) : value(val), left(NULL), right(NULL) {}
};

Node* insertTree(Node *node, int val) {
	if (node == NULL) return new Node(val);
	if (val < node->value) node->left = insertTree(node->left, val);
	else node->right = insertTree(node->right, val);
	return node;
}

void printTree(Node* node) {
	if (node == NULL) return;
	printTree(node->left);
	cout << node->value << " ";
	printTree(node->right);
}

long long solve(vector<int> &a) {
	Node *root = NULL;
	for (auto v : a) root = insertTree(root, v);
	printTree(root); cout << endl;
	
	return 0;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	do {
		cin >> N;
		if (N == 0) break;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) cin >> a[i];
		cout << solve(a) << endl;
	} while (true);
	
	return 0;
}