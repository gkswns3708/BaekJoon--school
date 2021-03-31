#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define MOD (int)(1e9+9)
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int dp[100000+1][3] = { 0, };
	dp[1][1] = dp[2][1] = dp[2][0] = 1,	dp[3][0] = 2,dp[3][1] = 2;

	for (int i = 4;i <= 100000;i++) {
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % MOD;
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;
	}
	int TC; cin >> TC;
	while (TC--) {
		int n; cin >> n;
		cout << dp[n][1] << " " << dp[n][0] << "\n";
	}
	return 0;
}