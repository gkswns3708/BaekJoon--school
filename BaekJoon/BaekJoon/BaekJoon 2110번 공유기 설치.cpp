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
	
	int N, k,ans = 0; cin >> N >> k;
	int lo = 1, hi = N*N;
	while (lo  <= hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 1; i <= N;i++) {
			cnt += min(N, mid / i);
			//cout <<mid <<"-mid "<< i << "번째 행에서 " << min(N, mid / i) << "개 나옴\n";
		}
		if (cnt < k) lo = mid + 1;
		else {
			ans = mid;
			hi = mid - 1;
		}
	}
	cout << ans;
	return 0;
}