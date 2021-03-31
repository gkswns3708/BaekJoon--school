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
	int TC; cin >> TC;
	int dp[100000 + 1] = { 0, };
	dp[1] = 1, dp[2] = 2,dp[3] = 4;
	for (int i = 4;i <= 100000;i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	while (TC--) {
		int n; cin >> n;
		if (n <= 3) cout << dp[n] << "\n";
		else if (n % 2 == 0) cout << (dp[n / 2] + dp[n / 2 - 1]) % MOD << "\n";
		else cout << (dp[(n - 1) / 2] + dp[(n - 3) / 2]) % MOD << "\n";
	}
	return 0;
}