#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int arr[100 + 1] = { 0, };
	int dist[100 + 1] = { 0, };
	fill(&dist[0], &dist[100+1], INF);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= 100;i++) arr[i] = i;
	for (int i = 0; i < N + M;i++) {
		int from, to; cin >>from >> to;
		arr[from] = to;
	}

	function<int(int)> BFS = [&](int st) ->int {
		queue<pii> que;
		que.push({ 0,st });
		dist[st] = 0;
		while (!que.empty()) {
			auto [ndist, pos] = que.front();
			if (pos == 100) return ndist;
			que.pop();
			for (int i = 1,npos; i <= 6;i++) {
				if (pos + i <= 100) npos = arr[pos + i];
				else continue;
				if (npos <=100 && dist[npos] > ndist + 1) dist[npos] = ndist+1,que.push({ ndist + 1, npos });
			}
		}
		return -1;
	};


	cout << BFS(1);

	return 0;
}