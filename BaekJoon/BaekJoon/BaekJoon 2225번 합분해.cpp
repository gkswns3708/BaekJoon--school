#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define MOD (int)1e9
using namespace std;

int dp[200 + 1][200 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	dp[0][0] = 1;
	for (int i = 0; i <= N;i++) {
		for (int k = 1; k <=K;k++) {
			for (int j = 0; j <= i;j++) {
				dp[i][k] += dp[i - j][k - 1];
				dp[i][k] %= MOD;
			}
		}
	}
	cout << dp[N][K];
	return 0;
}