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
	vector<int> vec(N);
	vector<int> ans;
	for (int i = 0; i < N;i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	function<void(int, int)> DFS = [&](int cnt, int pos)->void {
		if (cnt == M) {
			for (auto now : ans) cout << now << " ";
			cout << "\n";
		}
		else {
			for (int i = pos; i < N;i++) {
				ans.push_back(vec[i]);
				DFS(cnt + 1, i);
				ans.pop_back();
			}
		}
	};

	DFS(0, 0);

	return 0;
}