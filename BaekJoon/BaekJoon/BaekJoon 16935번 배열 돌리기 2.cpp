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

	int N, M, R; cin >> N >> M >> R;

	int arr[100 + 1][100 + 1];
	for (int i = 0; i < N;i++) for (int j = 0; j < M;j++) cin >> arr[i][j];

	function <void(int)> query = [&](int order)->void {
		switch (order) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;

		}
	};

	return 0;
}