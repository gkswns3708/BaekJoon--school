#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int arr[9 + 1][9 + 1] = { 0, };
	int fy,fx;
	bool f = 0;
	for (int i = 0; i < 9;i++) for (int j = 0; j < 9;j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 0 && !f) fy = i, fx = j, f = 1;
		
	}
	
	function <int(int,int)> BP = [&](int y, int x) ->int {
		bool check[10+1] = { 0, };
		bool flag = 0;
		int ny, nx;
		ny = (y / 3), nx = (x / 3);
		for (int i = 0; i < 9;i++) 	check[arr[y][i]] = check[arr[i][x]] = 1;
		for (int i = ny * 3; i < (ny + 1) * 3 ;i++) for (int j = nx * 3; j < (nx + 1) * 3 ;j++) check[arr[i][j]] = 1;
		for (int i = 1; i < 10;i++) if (!check[i]) flag = 1;

		if (!flag)return 0;
		int nxty, nxtx;
		bool find = 0;
		for (int TC = 1; TC <= 9;TC++) {
			if (check[TC] == 0) {
				arr[y][x] = TC;
				for (int i = 0; i < 9;i++) {
					if (find) break;
					for (int j = 0; j < 9;j++) {
						if (arr[i][j] == 0) {
							find = 1,nxty = i,nxtx = j;
							break;
						}
					}
				}
				if (!find) return 1;
				else if (BP(nxty, nxtx) == 1) return 1;
				else arr[y][x] = 0;
			}
		}
		return 0;
	};

	BP(fy, fx);
	for (int i = 0; i < 9;i++) {
		for (int j = 0; j < 9;j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}