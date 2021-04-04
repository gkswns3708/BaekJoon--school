#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define int long long
#define INF 987654321
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, st, ed; cin >> N >> M;
	vector<pii> edge[1000 + 1];
	vector<int> dist(N + 1, INF);
	for (int i = 0; i < M;i++) {
		int from, to, cost; cin >> from >> to >> cost;
		edge[from].push_back({ to,cost });
	}
	cin >> st >> ed;
	dist[st] = 0;
	auto dijkstra = [&]() {
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({ 0,st });
		while (!pq.empty()) {
			auto [ndist, pos] = pq.top();
			pq.pop();
			for (auto nxt : edge[pos]) {
				auto [nxtpos, cost] = nxt;
				int nxtdist = cost + ndist;
				if (dist[nxtpos] > nxtdist) dist[nxtpos] = nxtdist,	pq.push({ nxtdist,nxtpos });
			}
		}
	};
	dijkstra();
	cout << dist[ed];
	return 0;
}