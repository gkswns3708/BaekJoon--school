#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<int> que;
	int l, ml, mk, c; cin >> l >> ml >> mk >> c;
	int cnt = 0;
	for (int i = 1; i <= l;i++) {
		int z; cin >> z;
		int length = i >= ml ? ml : i;
		if (!que.empty() && que.front() < i - ml) que.pop();
		if (z > ((length - que.size()) * mk)) {
			que.push(i);
			c--;
		}
	}
	c < 0 ? cout << "NO" : cout << "YES";
}