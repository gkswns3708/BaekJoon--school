#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#define pii pair<int,int>
using namespace std;
int N, T;
vector<int> sp;
vector<pair<int, int>> map;
int dist[200 + 1][200 + 1];
int dp[1000 + 1][200 + 1];



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N;i++) {
		int c, e; cin >> c >> e;
		map.push_back({ c,e });
		if (c == 0) sp.push_back(i);
	}
	for (int i = 0; i < N;i++) 	for (int j = 0; j < N;j++) 	cin >> dist[i][j];
	memset(dp, -1, sizeof(dp));
	for (auto now : sp) dp[0][now] = 0;
	for (int i = 0; i < T;i++) {
		for (int j = 0; j < N;j++) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + map[j].second);
			for (int k = 0; k < N;k++) {
				if (j == k) continue;
				int time = dist[j][k];
				if (i + time > T || map[k].first > dp[i][j]) continue;
				dp[i + time][k] = max(dp[i + time][k], dp[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N;i++) ans = max(ans, dp[T][i]);
	cout << ans;

}