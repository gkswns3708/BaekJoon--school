#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int N, M;
bool visited[500000 + 1];
int parents[500000 + 1];

int _find(int a) {
	return parents[a] == a ? a : parents[a] = _find(parents[a]);
}

void _Union(int a, int b) {
	a = _find(a);
	b = _find(b);
	a < b ? parents[b] = a : parents[a] = b;	
}

void input() {
	cin >> N >> M;
}

void solution() {
	for (int i = 1; i <= N;i++) parents[i] = i;
	for (int i = 1; i <= M;i++) {
		int from, to; cin >> from >> to;
		if (_find(from) == _find(to)) cout << i, exit(0);
		else _Union(from, to);
	}
	cout << 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solution();
	return 0;
}