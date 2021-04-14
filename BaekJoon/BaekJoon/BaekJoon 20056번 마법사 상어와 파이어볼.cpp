#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define tiii tuple<int,int,int>
using namespace std;

int N, M, K;
vector<tiii> vec[50 + 1][50 + 1];
vector<tiii> tmp[50 + 1][50 + 1];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void input() {
	for (int i = 0; i < M;i++) {
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		vec[r - 1][c - 1].push_back({ m,s,d });
	}
}

void clear() {
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			vec[i][j].clear();
		}
	}
}
void cleartmp() {
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			tmp[i][j].clear();
		}
	}
}

int output() {
	int ans = 0;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			if (vec[i][j].size() == 0) continue;
			for (auto now : vec[i][j]) {
				auto [m, s, d] = now;
				ans += m;
			}
		}
	}
	return ans;
}

void move() {
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			if (vec[i][j].size() == 0) continue;
			for (auto now : vec[i][j]) {
				auto [m, s, d] = now;
				int y = (i + dy[d] * s) % N;
				int x = (j + dx[d] * s) % N;
				while (y < 0 || x < 0) y += N, x +=N;
				y %= N, x %= N;
				tmp[y][x].push_back(now);
			}
		}
	}
}

void cal() {
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			if (tmp[i][j].size() == 0) continue;
			if (tmp[i][j].size() >= 2) {
				int sumW = 0, sumS = 0, size = tmp[i][j].size();
				bool even = 0, odd = 0;
				for (auto now : tmp[i][j]) {
					auto [m, s, d] = now;
					sumW += m;
					sumS += s;
					if (d % 2 == 1) even = 1;
					else odd = 1;
				}
				tmp[i][j].clear();
				sumW /= 5;
				sumS /= size;
				if (sumW == 0) continue;
				else if (even & odd) for (int now : {1, 3, 5, 7}) vec[i][j].push_back({ sumW,sumS,now });
				else for (int now : {0, 2, 4, 6}) vec[i][j].push_back({ sumW,sumS,now });
			}
			else if (tmp[i][j].size() == 1) {
				auto [m, s, d] = tmp[i][j][0];
				vec[i][j].push_back({ m,s,d });
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	input();
	while (K--) {	
		cleartmp();
		move();
		clear();
		cal();
	}
	cout << output();
	return 0;
}