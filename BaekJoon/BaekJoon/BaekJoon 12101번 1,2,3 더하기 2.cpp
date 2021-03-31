#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0,n, k;
	cin >> n >> k;
	vector<int> vec;
	function <void(int, vector<int>&)> DP = [&](int now, vector<int>& vec) {
		if (now > n) return;
		if (now == n) {
			if (++cnt == k) {
				string s = "";
				for (auto now : vec) {
					s.push_back(now + '0');
					s.push_back('+');
				}
				s.pop_back();
				for (auto now : s) cout << now;
				exit(0);
			}
			return;
		}
		else {
			for (int i = 1; i <= 3;i++) {
				vec.push_back(i);
				DP(now + i, vec);
				vec.pop_back();
			}
		}
	};
	cout << typeid(DP(0,vec)).name()<<"\n";
	if (cnt < k) cout << -1;
	return 0;
}