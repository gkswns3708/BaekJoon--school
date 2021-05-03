#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int arr[1000 + 1][1000 + 1];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	int ans = 0;
	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= M;j++) {
			int now; cin >> now;
			if (now != 0) arr[i][j] = 0;
			else arr[i][j] = min({ arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1] })+1;
			ans = max(ans, arr[i][j]);
		}
	}
	cout << ans;
	return 0;
}