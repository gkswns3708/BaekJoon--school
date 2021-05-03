#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> vec1(N), vec2(N);
	for (int i = 0; i < N;i++) {
		int a, b; cin >> a >> b;
		vec1[i] = a + b;
		vec2[i] = a - b;
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	cout << max(vec1[N - 1] - vec1[0], vec2[N - 1] - vec2[0]);
	return 0;
}