#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int N, M, K;
int arr[40 + 1][40 + 1];

typedef struct Stick {
	int N, M;
	int arr[10 + 1][10 + 1];
}Stick;

Stick stick[100 + 1];

void printarr() {
	for (int y = 0; y < N;y++) {
		for (int x = 0; x < M;x++) {
			cout << arr[y][x] << " ";
		}
		cout << '\n';
	}
	cout << "\n";
}

bool OOB(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M) return true;
	else return false;
}

bool possible(int y, int x, Stick st, int dir) {
	int temp[40 + 1][40 + 1];
	for (int i = 0; i < N;i++) 	for (int j = 0; j < M;j++) 	temp[i][j] = arr[i][j];
	bool flag = true;
	if (dir == 0) {

		if (OOB(y + st.N - 1, x + st.M - 1)) {
			for (int i = y; i < y + st.N;i++) {
				for (int j = x; j < x + st.M;j++) {
					if (arr[i][j] == 1 && st.arr[i - y][j - x] == 1 || !OOB(i, j)) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = y; i < y + st.N;i++)
					for (int j = x; j < x + st.M;j++)
						if (st.arr[i - y][j - x] == 1) arr[i][j] = 1;
				return true;
			}
			flag = true;
		}
	}
	//90µµ
	if (dir == 1) {
		if (OOB(y + st.M - 1, x + st.N - 1)) {
			for (int i = y; i < y + st.M;i++) {
				for (int j = x; j < x + st.N;j++) {
					if (arr[i][j] == 1 && st.arr[x + st.N - j - 1][i - y] == 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = y; i < y + st.M;i++)
					for (int j = x; j < x + st.N;j++)
						if (st.arr[x + st.N - j - 1][i - y] == 1) arr[i][j] = 1;
				return true;
			}
			flag = true;
		}
	}
	//180µµ
	if (dir == 2) {
		if (OOB(y + st.N - 1, x + st.M - 1)) {
			for (int i = y; i < y + st.N;i++) {
				for (int j = x; j < x + st.M;j++) {
					if (arr[i][j] == 1 && st.arr[y + st.N - 1 - i][st.M + x - 1 - j] == 1 || !OOB(i, j)) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = y; i < y + st.N;i++)
					for (int j = x; j < x + st.M;j++) {
						if (st.arr[y + st.N - 1 - i][st.M + x - 1 - j] == 1)
							arr[i][j] = 1;
					}
				return true;
			}
			flag = true;
		}
	}
	//270µµ
	if (dir == 3) {
		if (OOB(y + st.M - 1, x + st.N - 1)) {
			for (int i = y; i < y + st.M;i++) {
				for (int j = x; j < x + st.N;j++) {
					if (arr[i][j] == 1 && st.arr[j - x][st.M + y - 1 - i] == 1 || !OOB(i, j)) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = y; i < y + st.M;i++)
					for (int j = x; j < x + st.N;j++) {
						if (st.arr[j - x][st.M + y - 1 - i] == 1)
							arr[i][j] = 1;
					}
				return true;
			}
		}
	}
	return false;
}
	


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K;i++) {
		int n, m; cin >> n >> m;
		for (int j = 0; j < n;j++) 	for (int k = 0; k < m;k++) 	cin >> stick[i].arr[j][k];
		stick[i].N = n;
		stick[i].M = m;
	}
	int cnt = 0;
	for (int k = 0; k < K;k++) {
		bool flag = false;
		for (int dir = 0; dir < 4;dir++) {
			if (flag) break;
			for (int i = 0;i < N;i++) {
				if (flag) break;
				for (int j = 0; j < M;j++) {
					if (flag) break;
					if (possible(i, j, stick[k],dir)) {
						//cout << k << "\n";
						//printarr();
						flag = true;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N;i++) 	for (int j = 0; j < M;j++) ans += arr[i][j];
	cout << ans;
	return 0;
}