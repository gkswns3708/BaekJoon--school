#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define int long long
using namespace std;

int arr[50 + 1][50 + 1];
int tmp[50 + 1][50 + 1];
int N, M, K;
int ans = INF;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
bool visited[10];
vector<tuple<int, int, int>> order;

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N;i++) for (int j = 1; j <= M;j++) cin >> arr[i][j];
	for (int i = 0; i < K;i++) {
		int r, c, s; cin >> r >> c >> s;
		order.push_back({ r,c,s });
	}
}

void rotateR(int r,int c, int s) {
	int sy = r - s, sx = c - s, temps = s;
	vector<vector<int>> vec1(s + 1, vector<int>(0));
	for (int pos = 0;pos < s ;pos++) {
		for (int q = 0; q < 4; q++) for (int i = 0; i < temps * 2;i++) 	vec1[pos].push_back(arr[sy][sx]), sy += dy[q], sx += dx[q];			
		sy++, sx++,temps--;
	}
	sy = r - s; sx = c - s, temps = s;
	for (int pos = 0;pos < s;pos++) {
		int cnt = 0;
		for (int q = 0; q < 4; q++) for (int i = 0; i < temps * 2;i++)arr[sy][sx] = vec1[pos][(cnt - 1 + vec1[pos].size()) % vec1[pos].size()], sy += dy[q], sx += dx[q], cnt++;	
		sy++, sx++, temps--;
	}
}

void DFS(int cnt) {
	if (cnt == K) {
		for (int i = 1; i <= N;i++) {
			int sum = 0;
			for (int j = 1; j <= M;j++) sum += arr[i][j];
			ans = min(ans, sum);
		}
		return;
	}
	for (int i = 0; i < K;i++) {
		if (visited[i]) continue;
		int saved[50 + 1][50 + 1] = { 0, };
		visited[i] = 1;
		for (int y = 1; y <= N;y++) for (int x = 1; x <= M;x++) saved[y][x] = arr[y][x];
		auto [r, c, s] = order[i];
		rotateR(r,c,s);
		DFS(cnt + 1);
		visited[i] = 0;
		for (int y = 1; y <= N;y++) for (int x = 1; x <= M;x++) arr[y][x] = saved[y][x];
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	DFS(0);
	cout << ans << "\n";
	return 0;
}