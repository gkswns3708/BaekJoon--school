#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

char arr[510][510];
int N, M;

int possible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) {
		//구멍이면 H 돌이면 1이라서 빼기 1칸 해야함
		//E라면 종결 그외는 이동 가능.
		if (arr[y][x] == 'H') return -1;
		else if (arr[y][x] == 'R') return 1;
		else if (arr[y][x] == 'E') return 2;
		else return 0;
	}
	else {
		return -1;
	}
}

tuple<int, int, int> move(tuple<int, int, int, int> now) {
	auto [y, x, dist, dir] = now;
	while (1) {
		bool flag = false;
		int nx = x + "2101"[dir] - '1';
		int ny = y + "1210"[dir] - '1';
		switch (possible(ny, nx)) {
		case 0:
			break;
		case 1:
			return { y,x,dist };
			break;
		case 2:
			return { ny,nx,dist };
			break;
		case -1:
			return { -1,-1,-1 };
			break;
		}
		x = nx;
		y = ny;
		dist++;
	}
}

int solution(pair<int, int> st,pair<int,int> ed) {
	int ans = INF;
	queue<tuple<int, int, int>> que;
	que.push({ st.first, st.second, 0 });
	while (!que.empty()) {
		auto [y, x, dist] = que.front();
		if (y == ed.first && x == ed.second) ans = min(ans, dist);
		que.pop();
		cout << y<<" " <<x << " " <<dist<<"\n";
		for (int i = 0; i < 4;i++) {
			auto [ny,nx,ndist] = move({ y,x,dist,i });
			if (ny != -1) que.push({ ny,nx,ndist });
		}
	}
	return ans == INF ? -1 : ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	pair<int, int > st,ed;
	for (int i = 0; i < N;i++) for (int j = 0; j < M;j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'T') st.first = i, st.second = j;
		else if (arr[i][j] == 'E') ed.first = i, ed.second = j;
	}

	cout << solution(st,ed);

	
}