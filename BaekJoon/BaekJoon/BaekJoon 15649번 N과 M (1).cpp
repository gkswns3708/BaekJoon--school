#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
using namespace std;
int k;
vector<int> vec(8+1);
bool visited[8 + 1] = { 0, };
int N, M;
void BT(int cnt, int pos) {
	if (cnt == M) {
		for (int i = 0; i < M;i++) cout << vec[i] << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= N;i++) {
			if (visited[i]) continue;
			vec[k++]= i;
			visited[i] = 1;
			BT(cnt + 1, i);
			k--;
			visited[i] = 0;
		}
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	BT(0, 0);
	return 0;
}