#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	vector<int> vec(N);
	int DP[5000 + 1] = { 0, };
	for (int i = 0; i < N;i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 1; i < vec.size();i++) {
		for (int j = 0; j < i;j++) {
			if (vec[i] % vec[j] == 0) DP[i] = max(DP[i], DP[j] + 1);
		}
	}
	cout << N - 1 - *max_element(DP, DP + N);
}