#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define int long long
#define INF 987654321
using namespace std;

int dist[20000 + 1];
vector<pii> edge[20000 + 1];
int V, E, start;

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		auto [ndist, pos] = pq.top();
		pq.pop();
		for (auto nxt : edge[pos]) {
			auto [nxtpos, cost] = nxt;
			int ncost = cost + ndist;
			if (dist[nxtpos] > ncost) dist[nxtpos] = ncost,pq.push({ ncost,nxtpos });
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E >> start;
	for (int i = 0; i < E;i++) {
		int u, v, w;cin >> u>> v>> w;
		edge[u].push_back({v, w});
	}
	for (int i = 1; i <= V;i++) dist[i] = INF;
	dist[start] = 0;
	dijkstra();
	for (int i = 1; i <= V;i++) dist[i] == INF ? cout << "INF" << "\n" : cout << dist[i] << "\n";
	return 0;
}