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
	vector<int> vec(N + 1);
	vector<int> ans, lastuse(N + 1);
	vector<bool> visited(N + 1);
	int pre = -1;
	for (int i = 0; i < N;i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	function<void(int, int)> DFS = [&](int cnt, int pos)->void {
		if (cnt == M) {
			for (auto now : ans) cout << now << " ";
			cout << "\n";
		}
		else {
			for (int i = pos; i < vec.size();i++) {
				if (lastuse[ans.size()] == vec[i]) continue;
				lastuse[ans.size()] = vec[i];
				ans.push_back(vec[i]);
				DFS(cnt + 1, i);
				lastuse[ans.size()] = 0;
				ans.pop_back();
			}
		}
	};

	DFS(0, 0);

	return 0;
}