#include <iostream>
#include <vector>
#include <algorithm>
#define INF 98765421
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N;i++) dist[i][i] = 0;
	for (int i = 0; i < M;i++) {
		int from, to, cost; cin >> from >> to >> cost;
		dist[from][to] = min(dist[from][to], cost);
	}


	for (int k = 1; k <= N;k++) {
		for (int i = 1; i <= N;i++) {
			for (int j = 1; j <= N;j++) {
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= N;j++) dist[i][j] == INF ? cout << "0 " : cout << dist[i][j] << " ";
		cout << "\n";
	}

	return 0;
}