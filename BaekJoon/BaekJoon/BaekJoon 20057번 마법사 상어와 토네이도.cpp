#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define tiii tuple<int,int,int>
#define int long long
using namespace std;

int N;
int arr[500 + 1][500 + 1];
int dy1[4] = { 0,1,0,-1 };
int dx1[4] = { -1,0,1,0 };
int dy[4] = { 0, 2 ,0 ,-2};
int dx[4] = { -2 ,0,2,0 };
int ans;

tiii cal[4][10] = {
	{{-1,0,1},{1,0,1},{1,-1,7},{-1,-1,7},{2,-1,2},{-2,-1,2},{1,-2,10},{-1,-2,10},{0,-3,5}},//L
	{{0,-1,1},{0,1,1},{1,-1,7},{1,1,7},{1,-2,2},{1,2,2},{2,-1,10},{2,1,10},{3,0,5}},//D
	{{-1,0,1},{1,0,1},{1,1,7},{-1,1,7},{2,1,2},{-2,1,2},{1,2,10},{-1,2,10},{0,3,5}}, // R
	{{0,1,1},{0,-1,1},{-1,-1,7},{-1,1,7},{-1,-2,2},{-1,2,2},{-2,-1,10},{-2,1,10},{-3,0,5}}//U
};

bool possible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N) return true;
	else return false;
}

void fcal(int y, int x,int dir) {
	int first = arr[y + dy1[dir]][x + dx1[dir]];
	for (int i = 0; i < 9;i++) {
		auto [ddy, ddx, num] = cal[dir][i];
		int ny = y + ddy;
		int nx = x + ddx;
		int nowsand = (arr[y + dy1[dir]][x + dx1[dir]] * num) / 100;
		if (possible(ny, nx)) arr[ny][nx] += nowsand, first-= nowsand;
		else ans += nowsand, first -= nowsand;
	}
	if (possible(y + dy[dir], x + dx[dir])) arr[y + dy[dir]][x + dx[dir]] += first;
	else ans += first;
	arr[y + dy1[dir]][x + dx1[dir]] = 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N;i++) for (int j = 0; j < N;j++) cin >> arr[i][j];	
	int y = N / 2, x = N / 2;
	for (int d = 1; d < N;d++) {
		for (int i = 0; i < d;i++) fcal(y, x--,0);
		for (int i = 0; i < d;i++) fcal(y++, x,1);
		d++;
		for (int i = 0; i < d;i++) fcal(y, x++,2);
		for (int i = 0; i < d;i++) fcal(y--, x,3);
	}
	for (int i = 0; i < N-1;i++) fcal(y, x--, 0);
	cout << ans; 
	return 0;
}