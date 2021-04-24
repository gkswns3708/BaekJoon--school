#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

int N, M, K;
bool visited[1000 + 1][1000 + 1][2];
int arr[1000 + 1][1000 + 1];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool possible(int y, int x, int k, bool day) {
	if (y >= 1 && x >= 1 && y <= N && x <= M && k <= K && !visited[y][x][day]) return true;
	else return false;
}

void input() {
	cin >> N >> M>> K;
	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= M; j++) {
			char a; cin >> a;
			arr[i][j] = a - '0';
		}
	}
}

void solution() {
	queue<tuple<int, int, int, bool>> que;
	que.push({1,1,0,0 });//1,1에서 시작해 부순 벽의 갯수는 0개, 낮
	visited[1][1][0] = 1;
	int dist = 1;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			auto [y, x, k, day] = que.front();
			//cout << y << " " << x << " " << k << " " << day << "\n";
			que.pop();
			if (y == N && x == M) cout << dist, exit(0);
			for (int i = 0; i < 4;i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (arr[ny][nx] == 1 && day == 0 && possible(ny,nx,k+1,!day)) {
					visited[ny][nx][!day] = 1;
					que.push({ny,nx,k + 1,!day });
				}
				else if (arr[ny][nx] == 1 && day == 1 && possible(ny, nx, k, !day)) {
					if (visited[y][x][!day]) continue;
					else {
						visited[y][x][!day] = 1;
						que.push({y,x,k,!day});
					}
				}
				else {
					if (possible(ny, nx, k, !day)) {
						visited[ny][nx][!day] = 1;
						que.push({ ny,nx,k,!day });
					}				
				}
			}
		}
		dist++;
	}
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solution();
	return 0;
}