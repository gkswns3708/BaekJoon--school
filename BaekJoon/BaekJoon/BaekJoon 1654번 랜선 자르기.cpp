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
	int N, K; cin >> N >> K;
	vector<int> vec(N);
	for (int i = 0; i < N;i++) cin >> vec[i];

	int st = 1, ed = INT_MAX*1LL + 1;
	while (st + 1 < ed) {
		int mid = (st + ed) / 2;
		int cnt = 0;
		for (auto now : vec) cnt += now / mid;
		if (cnt < K) ed = mid;
		else st = mid;
	}
	cout << st;
	return 0;
}