#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prime;
bool is_prime[1500];
int ans[1120 + 1][14 + 1];
int n, k;

void linear_sieve() {
	for (int i = 2; i <= 1120;++i) {
		if (!is_prime[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] <= 1120;++j) {
			is_prime[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

void cal() {
	for (int i = 0; i < prime.size();i++) {
		for (int j = 1120; j >= prime[i];j--) {
			for (int k = 1;k <= 14;k++) {
				ans[j][k] += ans[j - prime[i]][k - 1];
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	linear_sieve();
	int TC; cin >> TC;
	ans[0][0] = 1;
	cal();
	while (TC--) {
		cin >> n >> k;
		cout << ans[n][k] << "\n";
	}
}