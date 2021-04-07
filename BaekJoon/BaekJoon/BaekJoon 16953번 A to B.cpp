#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#define pii pair<int,int>
#define int long long
using namespace std;
#define MAX (int)1e9

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B;cin >> A >> B;
	function<int(int,int)> BFS = [&](int st, int ed) -> int {
		queue<pii> que;
		map<int, int> visited;
		que.push({ 0,st });
		visited[st] = 1;
		while (!que.empty()) {
			auto [dist, now] = que.front();
			if (now == ed) return dist + 1;
			que.pop();
			if (now * 2 <= MAX && visited[now * 2] == 0) visited[now * 2] = 1, que.push({ dist + 1,now * 2 });
			if (now * 10 + 1 <= MAX && visited[now * 10 + 1] == 0) visited[now * 10 + 1] = 1, que.push({ dist + 1,now * 10 + 1 });
		}
		return -1;
	};
	
	cout << BFS(A, B);


	return 0;
}