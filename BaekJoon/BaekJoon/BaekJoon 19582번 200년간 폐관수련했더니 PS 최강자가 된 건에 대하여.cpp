#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,sum = 0,mx = 0,cant = 0; cin >> N;
	for (int i = 0; i < N;i++) {
		int x, p; cin >> x >> p;
		if (sum <= x) {
			sum += p;
			mx = max(mx, p);
		}
		else if (sum - mx > x || mx < p) cant++;
		else {
			cant++;
			sum -= mx;
			sum += p;
		}
		if (cant == 2) {
			cout << "Zzz";
			return 0;
		}
	}
	cout << "Kkeo-eok";
	return 0;
}