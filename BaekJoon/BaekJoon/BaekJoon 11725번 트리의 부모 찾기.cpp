#include <bits/stdc++.h>
#define int long long
using namespace std;
bool visited[1000000 + 1];
int parents[100000 + 1];
vector<int> edge[100000 + 1];
int a, b;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N-1;i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	function <void()> BFS = [&]() -> void {
		queue<int> que;
		que.push(1);
		visited[1] = 1;
		while (!que.empty()) {
			auto now = que.front();
			que.pop();
			for (auto nxt : edge[now]) {
				if (!visited[nxt]) {
					que.push(nxt);
					visited[nxt] = 1;
					parents[nxt] = now;
				}
			}
		}
	};
	BFS();
	for (int i = 2; i <= N;i++) cout << parents[i] << "\n";
	return 0;

}