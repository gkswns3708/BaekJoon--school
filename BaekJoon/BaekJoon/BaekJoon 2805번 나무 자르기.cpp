#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> vec(N);
	for (int i = 0; i < N;i++) cin >> vec[i];
	int lo = 0, hi = INT_MAX;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int len = 0;
		for (auto now : vec) now - mid > 0 ? len += now - mid : 0;
		if (len < M)hi = mid;
		else lo = mid;
	}
	cout << lo;
	return 0;
}