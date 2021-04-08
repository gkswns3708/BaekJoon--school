
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

	int N, M; cin >> N >> M;
	vector<int> vec;
	bool visited[8 + 1] = { 0, };
	function <void(int, int)> BT = [&](int cnt, int pos) ->void {
		if (cnt == M) {
			for (auto now : vec) cout << now << " ";
			cout << "\n";
			return;
		}
		else {
			for (int i = 1; i <= N;i++) {
				if (visited[i]) continue;
				vec.push_back(i);
				visited[i] = 1;
				BT(cnt + 1, i);
				vec.pop_back();
				visited[i] = 0;
			}
		}
	};
	BT(0, 0);
	return 0;
}