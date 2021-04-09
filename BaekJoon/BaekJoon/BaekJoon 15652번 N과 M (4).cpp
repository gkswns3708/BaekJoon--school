#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> vec;
	function<void(int, int)> DFS = [&](int cnt, int pos)->void {
		if (cnt == M) {
			for (auto now : vec) cout << now << " ";
			cout << "\n";
		}
		else {
			for (int i = pos; i <= N;i++) {
				vec.push_back(i);
				DFS(cnt + 1, i);
				vec.pop_back();
			}
		}
	};

	DFS(0, 1);

	return 0;
}