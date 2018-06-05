#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long r = a % b; a = b; b = r;
	}
	return a;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	long long a, b; char c;
	cin >> a >> c >> b;
	
	long long m = 5 * (a - 32 * b);
	long long d = 9 * b;
	long long g = gcd(m, d);
	if (g < 0) g = -g;
	cout << (m / g) << "/" << (d / g) << endl;
	
	return 0;
}