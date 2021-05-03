#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int sum[1000 + 1][1000 + 1];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C, Q; cin >> R >> C >> Q;
	for (int i = 1; i <= R;i++) {
		for (int j = 1; j <= C;j++) {
			int now; cin >> now;
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + now;
		}
	}
	for (int i = 0; i < Q;i++) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
		int now = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
		cout << now / ((r2 - r1 + 1) * (c2 - c1 + 1)) <<"\n";
	}
	return 0;
}