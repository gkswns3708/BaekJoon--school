#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define int long long
#define MOD (int)(1e9+9)
using namespace std;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC; cin >> TC;
	
	int dp[1000000 + 1];
	memset(dp, -1, sizeof(dp));
	dp[1] = 1, dp[2] = 2, dp[3] = 4;

	auto DP = [&](int n) {
		for (int i = 4; i <= n;i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%MOD;
	};
	DP(1000000);
	while (TC--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}