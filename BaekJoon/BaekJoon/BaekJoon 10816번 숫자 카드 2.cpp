#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int arr[500000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N;i++) cin >> arr[i];
	int M; cin >> M;
	sort(arr, arr + N);
	for (int i = 0; i < M;i++) {
		int now; cin >> now;
		cout << upper_bound(arr, arr + N, now) - lower_bound(arr, arr + N, now) << "\n";
	}
	return 0;
}