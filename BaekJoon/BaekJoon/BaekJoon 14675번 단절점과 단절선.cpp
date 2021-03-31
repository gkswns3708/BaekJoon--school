#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;

vector<int> edge[100000 + 1];
bool visited[100000 + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1;i++) {
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	cin >> M;
	for (int i = 0; i < M;i++) {
		int t, k; cin >> t >> k;
		if (t == 2) cout << "yes\n";
		else if (t == 1) edge[k].size() >= 2 ? cout << "yes\n" : cout << "no\n";
	}
	return 0;
}