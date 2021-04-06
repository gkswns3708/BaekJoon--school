#pragma warning(disable:6200)
#pragma warning(disable:6385)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#define pii pair<int,int>
#define int long long
using namespace std;
int W, H;
int arr[50 + 1][50 + 1];
bool visited[50 + 1][50 + 1];

bool possible(int y, int x) {
	if (y >= 0 && y < H && x >= 0 && x < W && arr[y][x] == 1 && !visited[y][x]) return true;
	else return false;
}

void BFS(int y, int x) {
	queue<pii> que;
	que.push({ y,x });
	visited[y][x] = 1;
	while (!que.empty()) {
		auto [ny, nx] = que.front();
		que.pop();
		for (int i = 0; i < 8;i++) {
			int nxty = ny + "00012221"[i] - '1';
			int nxtx = nx + "01222100"[i] - '1';
			if (possible(nxty, nxtx)) que.push({ nxty,nxtx }), visited[nxty][nxtx] = 1;
 		}

	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		fill(arr[0], arr[51], 0);
		fill(visited[0], visited[51], 0);
		for (int i = 0; i < H;i++) 	for (int j = 0; j < W;j++) cin >> arr[i][j];
		int ans = 0;
		for (int i = 0; i < H;i++)for (int j = 0; j < W;j++) if(arr[i][j] && !visited[i][j]) BFS(i,j),ans++;
		cout << ans << "\n";
	}
	return 0;
}