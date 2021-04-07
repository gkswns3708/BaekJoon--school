#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> edge[1000 + 1];
	vector<int> visited(N+1,0);
	for (int i = 0; i < M;i++) {
		int from, to; cin >> from >> to;
		edge[from].push_back({ to });
		edge[to].push_back({ from });
	}

	auto BFS = [&](int st) {
		queue<int> que;
		que.push({ st });
		visited[st] = 1;
		while (!que.empty()) {
			auto now = que.front();
			que.pop();
			for (auto nxt : edge[now]) {
				if (visited[nxt]) continue;
				que.push(nxt);
				visited[nxt] = 1;
			}
		}
	};

	int ans = 0;

	for (int i = 1; i <= N;i++) {
		if (visited[i]) continue;
		BFS(i);
		ans++;
	}
	cout << ans;
	return 0;
}