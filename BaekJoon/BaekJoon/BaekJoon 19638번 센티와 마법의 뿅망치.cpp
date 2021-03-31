#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, H, T, i;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> H >> T;
	priority_queue<int> pq;
	for (i = 0; i < N;i++) {
		int num; cin >> num;
		pq.push(num);
	}
	for (i = 0; i < T;i++) {
		auto now = pq.top();
		if (now < H || now == 1) break;
		pq.pop();
		pq.push(now / 2);
	}
	if (pq.top() < H) cout << "YES\n" << i;
	else cout << "NO\n" << pq.top();

}