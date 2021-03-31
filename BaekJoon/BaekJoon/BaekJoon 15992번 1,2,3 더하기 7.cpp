#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define MOD (int)(1e9+9)
using namespace std;

int dp[1000 + 1][1000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dp[1][1] = dp[2][1] = dp[3][1] = dp[2][2] =dp[3][3] = 1;
	dp[3][2] = 2;

	for (int i = 4; i <= 1000;i++) {
		for (int j = 2; j <= 1000;j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % MOD;
		}
	}
	int TC; cin >> TC;
	while (TC--) {
		int n, m;cin >> n >> m;
		cout << dp[n][m] << "\n";
	}
	return 0;
}