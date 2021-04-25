#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int root, last, ans;
	bool flag = true;
	vector<int> vec;
	vector<int> edge[50 + 1];
	vector<int> parents(N + 1);
	vector<int> parents2(N + 1);
	int visited[50+1];
	for (int i = 0; i < N;i++) {
		cin >> parents[i];
		if (parents[i] == -1) root = i;
		else edge[parents[i]].push_back(i);
	}

	auto BFS = [&](int root) -> int {
		memset(visited, false, sizeof(visited));
		int ans = 0;
		queue<int> que;
		que.push(root);
		visited[root] = 1;
		while (!que.empty()) {
			auto now = que.front();
			que.pop();
			if (edge[now].size() == 0)ans++;
			for (auto nxt : edge[now]) {
				if (!visited[nxt]) {
					visited[nxt] = 1;
					que.push(nxt);
				}
			}
		}
		return ans;
	};

	ans = BFS(root);
	cin >> last;
	ans -= BFS(last);
	if (edge[parents[last]].size() == 1) ans++;
	cout << ans;
	return 0;
}