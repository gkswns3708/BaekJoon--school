#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

bool visited[200000 + 1];
char s[200000 + 1];


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;
	vector<int> pos;
	for (int i = 0; i < N;i++) {
		cin >> s[i];
		if(s[i] == 'P')	pos.push_back(i);
	}

	int ans = 0;

	for (auto npos : pos) {
		bool flag = false;
		for (int len = K; len >= 1;len--) {
			if (npos - len < 0) continue;
			else if (s[npos - len] == 'H' && !visited[npos - len]) {
				flag = true, ans++, visited[npos - len] = 1;
				break;
			}
			
		}
		if (!flag) {
			for (int len = K; len >= 1;len--) {
				if (npos + len >= N) continue;
				else if (s[npos + len] == 'H' && !visited[npos + len]) {
					ans++, visited[npos + len] = 1;
					break;
				}

			}
		}
	}
	cout << ans;
	return 0;
}