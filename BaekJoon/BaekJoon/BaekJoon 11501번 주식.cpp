#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC;cin >> TC;
	while (TC--) {
		int N; cin >> N;
		vector<int> vec(N);
		for (int i = 0; i < N;i++) 	cin >> vec[i];
		int maxvalue = vec[N - 1];
		int ans = 0;
		for (int i = N - 2;i >= 0;i--) {
			if (maxvalue < vec[i]) 	maxvalue = vec[i];
			else ans += maxvalue - vec[i];
		}
		cout << ans << "\n";
	}
}