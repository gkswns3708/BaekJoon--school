#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt1 = 0, cnt2 = 0, sum = 0;
	int N; cin >> N;
	for (int i = 0; i < N;i++) {
		int now; cin >> now;
		cnt2 += now / 2;
		sum += now;
	}
	cnt2 >= sum/3 && sum%3 == 0 ? cout << "YES" : cout << "NO";
	return 0;
}