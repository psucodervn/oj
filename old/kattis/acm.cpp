#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int minute;
	string prob, status;
	map<string, int> mp;
	while (true) {
		cin >> minute; if (minute < 0) break;
		cin >> prob >> status;
		if (mp[prob] > 0) continue;
		if (status == "wrong") {
			mp[prob] -= 20;
		} else {
			mp[prob] = minute - mp[prob];
		}
	}
	int totalProb = 0, totalPenalties = 0;
	for (auto p : mp) {
		if (p.second > 0) { totalProb++; totalPenalties += p.second; }
	}
	cout << totalProb << " " << totalPenalties << endl;
	
	return 0;
}