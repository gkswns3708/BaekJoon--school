#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, ans = 0; cin >> N;
	vector<int> vec(N);
	function <void(int)> DFS = [&](int cnt) ->void {
		bool possible;
		if (cnt == N) {
			ans++;
			return;
		}
		for (int i = 0; i < N;i++) {
			bool flag = 1;
			for (int j = 0; j < cnt;j++) {
				if (vec[j] == i || abs(cnt - j) == abs(i - vec[j])) {
					flag = false;
					break;
				}
			}
			if (flag) {
				vec[cnt] = i;
				DFS(cnt + 1);
			}
		}
	};

	DFS(0);
	cout << ans;
	return 0;
}