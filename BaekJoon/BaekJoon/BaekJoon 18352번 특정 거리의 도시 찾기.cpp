#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define int long long
using namespace std;

vector<int> edge[300000 + 1];
bool visited[300000 + 1];
vector<int> dist(300000+1);
void BFS(int st) {
	queue<pii> que;
	que.push({ 0,st });
	visited[st] = 1;
	while (!que.empty()) {
		auto [ndist, pos] = que.front();		
		dist[pos] = ndist;
		que.pop();
		for (auto nxt : edge[pos]) 	
			if (!visited[nxt])
				que.push({ndist+1,nxt}), visited[nxt] = 1;
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K, X; cin >> N >> M >> K >> X;
	for (int i = 0; i < M;i++) {
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
	}

	BFS(X);
	vector<int> ans;
	for (int i = 1; i <= N;i++) if (dist[i] == K) ans.push_back(i);
	
	if (ans.size() == 0) cout << -1;
	else for (auto now : ans) cout << now << "\n";

	return 0;
}