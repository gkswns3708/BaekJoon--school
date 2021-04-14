#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
#define pii pair<int , int>
using namespace std;

int arr[1000 + 2][1000 + 2];
pii check[1000 + 1][1000 + 1];
int ans[1000 + 2][1000 + 2];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int N, M, R; cin >> N >> M >> R;
	vector<vector<int>> vec(min(N, M) / 2 + 1);
	for (int i = 1; i <= N;i++) for (int j = 1; j <= M;j++) cin >> arr[i][j];

	function <void(int)> search = [&](int x) -> void {
		pii st = { x,x };
		int cnt = 0;
		while (st.second <= M + 1 - x) check[st.first][st.second] = { x,cnt++ }, vec[x].push_back(arr[st.first][st.second++]);
		st.second--, st.first++;
		while (st.first <= N + 1 - x) check[st.first][st.second] = { x,cnt++ }, vec[x].push_back(arr[st.first++][st.second]);
		st.first--, st.second--;
		while (st.second >= x) check[st.first][st.second] = { x,cnt++ }, vec[x].push_back(arr[st.first][st.second--]);
		st.second++, st.first--;
		while (st.first >= x + 1) check[st.first][st.second] = { x,cnt++ }, vec[x].push_back(arr[st.first--][st.second]);
	};
	for (int i = 1; i <= min(N, M) / 2;i++) search(i);
	for (int i = 1; i <= N;i++) for (int j = 1; j <= M;j++) ans[i][j] = vec[check[i][j].first][(check[i][j].second + R) % vec[check[i][j].first].size()];;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M;j++) cout << ans[i][j] << " ";
		cout << '\n';
	}

	return 0;
}