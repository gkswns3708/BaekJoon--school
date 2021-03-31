#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> edge[100000 + 1];
vector<int> order;
int N;
int cnt;
bool flag;
void dfs(int now) {
	while (edge[now].find(order[cnt + 1]) != edge[now].end()) dfs(order[++cnt]);	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1;i++) {
		int from, to; cin >> from >> to;
		edge[from].insert(to);
		edge[to].insert(from);
	}
	order.resize(N+1);
	for (int i = 0; i < N;i++) cin >> order[i];
	dfs(order[0]);
	if (order[0] != 1) {
		cout << 0 << "\n";
		return 0;
	}
	cnt == N-1? cout << 1 << "\n": cout << 0 << "\n";
	return 0;
}