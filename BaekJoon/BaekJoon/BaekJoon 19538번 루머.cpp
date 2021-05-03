#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;


vector<int> edge[200000 + 1];
int cnt[200000 + 1];

vector<int> dist(200000, -1);

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 1,nxt; i <= N;i++) while (cin >> nxt && nxt != 0) 	edge[i].push_back(nxt);

	function <void()> BFS = [&]()->void {
		int M; cin >> M;
		queue<int> que;
		for (int i = 0; i < M;i++) {
			int root; cin >> root;
			que.push(root);
			dist[root] = 0;
			for(auto now : edge[root]) cnt[now]++;
		}
		int dst = 0;
		while (!que.empty()) {
			int size = que.size();
			vector<int> cnt2;
			queue<int> que2;
			while (size--) {
				auto now = que.front();	que.pop();
				for (auto nxt : edge[now]) {
					if (dist[nxt] != -1 || cnt[nxt] * 2 < edge[nxt].size()) continue;
					dist[nxt] = dist[now] + 1, que2.push(nxt);
				}
			}
			while (!que2.empty()) {
				auto now = que2.front();que2.pop();
				que.push(now);
				for (auto nxt : edge[now]) cnt[nxt]++;
			}
			dst++;
		}
	};

	BFS();
	for (int i = 1; i <= N;i++) cout << dist[i] << " ";
	
	return 0;
}