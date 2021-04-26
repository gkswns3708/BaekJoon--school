#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N; cin >> N;
	vector<pii> edge[10000 + 1];
	bool visited[10000 + 1];
	for (int i = 0; i < N - 1;i++) {
		int from, to, dist; cin >> from >> to >> dist;
		edge[from].push_back({ to,dist });
		edge[to].push_back({ from,dist });
	}
	function <pii(int)> BFS = [&](int root) ->pii {
		memset(visited, 0, sizeof(visited));
		pii ans = { -1,-1 };
		queue<pii> que;
		que.push({ root,0 });
		visited[root] = 1;
		while (!que.empty()) {
			auto [now, dist] = que.front();
			if (ans.second < dist) ans = que.front();
			que.pop();
			for (auto nxt : edge[now]) {
				auto [nxtpos, cost] = nxt;
				if(!visited[nxtpos]) que.push({ nxtpos,cost + dist }),visited[nxtpos] = 1;
			}
		}
		return ans;		
	};

	int maxpoint = BFS(1).first;
	cout << BFS(maxpoint).second;

	return 0;
}