#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

int arr[64 + 1][64 + 1];
int tmp[64 + 1][64 + 1];
bool visited[64 + 1][64 + 1];
int N, Q;
int arrsize;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool possible(int y, int x) {
	if (y >= 0 && y < arrsize && x >= 0 && x < arrsize) return true;
	else return false;
}

void rotateR(int sy, int sx, int s) {
	for (int i = 0; i < s;i++) for (int j = 0; j < s;j++) tmp[i][s - 1 - j] = arr[sy + j][sx + i];
	for (int i = 0; i < s;i++) for (int j = 0; j < s;j++) arr[sy + i][sx + j] = tmp[i][j];	
}

void rotate(int q) {
	int s = 1 << q;
	for (int i = 0; i < arrsize;i += s) {
		for (int j = 0; j < arrsize; j += s) {
			int sy = i, sx = j;
			rotateR(sy, sx, s);
		}
	}
}

void checkice() {
	for (int y = 0; y < arrsize;y++) for (int x = 0; x < arrsize;x++) tmp[y][x] = arr[y][x];
	for (int y = 0; y < arrsize;y++) {
		for (int x = 0; x < arrsize;x++) {
			int cnt = 0;
			for (int i = 0; i < 4;i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (!possible(ny, nx)) continue;
				if (arr[ny][nx] > 0) cnt++;
			}
			if (cnt < 3) tmp[y][x]--;
		}
	}
	for (int y = 0; y < arrsize;y++) for (int x = 0; x < arrsize;x++) arr[y][x] = tmp[y][x];
}

int BFS(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> que;
	que.push({ y,x });
	int ret = 0;
	while (!que.empty()) {
		auto [ny, nx] = que.front();
		ret++;
		que.pop();
		for (int i = 0; i < 4;i++) {
			int nny = ny + dy[i];
			int nnx = nx + dx[i];
			if (possible(nny, nnx) && !visited[nny][nnx] && arr[nny][nnx] > 0) {
				visited[nny][nnx] = 1;
				que.push({ nny,nnx });
			}
		}
	}
	return ret;
}

void printans() {
	int ans = 0;
	for (int i = 0; i < arrsize;i++) for (int j = 0; j < arrsize;j++) arr[i][j] > 0 ? ans+=arr[i][j] : 0;
	cout << ans<<"\n";
	int maxvalue = 0;
	for (int i = 0; i < arrsize;i++) for (int j = 0; j < arrsize;j++) {
		if (!visited[i][j] && arr[i][j] > 0) {
			maxvalue = max(maxvalue,BFS(i, j));
		}
	}
	cout << maxvalue << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	arrsize = 1 << N;
	for (int i = 0; i < arrsize; i++ ) for (int j = 0; j < arrsize;j++) cin >> arr[i][j];
	while (Q--) {
		int q; cin >> q;
		rotate(q);
		checkice();
	}
	printans();
	return 0;
}