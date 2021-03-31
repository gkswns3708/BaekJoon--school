#include <iostream>
#include <queue>
#include <memory.h>
#define INF 987654321



int arr[50 + 1][50 + 1];
int N, M;
bool visited[50 + 1][50 + 1];
bool possible(int y, int x) {
	if (y < N && y >= 0 && x < M && x >= 0 && !visited[y][x]) return true;
	else return false;
}

using namespace std;

int BFS(int sy, int sx) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> que;
	que.push({ sy,sx});
	visited[sy][sx] = 1;

	int dist = 0;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			auto [y, x] = que.front();
			que.pop();
			if (arr[y][x] == 1) return dist;
			for (int i = 0; i < 8;i++) {
				int nx = x + "22100012"[i] - '1';
				int ny = y + "12221000"[i] - '1';
				if (possible(ny, nx)) {
					que.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
		dist++;
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N;i++) 
		for (int j = 0; j < M;j++) 
			cin >> arr[i][j];
	
	int ans = 0;

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M;j++) {
			if (arr[i][j] == 0) ans = max(ans, BFS(i, j));
		}
	}

	cout << ans;;
	return 0;
}
