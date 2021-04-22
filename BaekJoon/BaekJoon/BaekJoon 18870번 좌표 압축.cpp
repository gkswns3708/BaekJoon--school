#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#define int long long
using namespace std;

unordered_map<int, int> umap;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	map<int, int> mp,ans;
	vector<int> vec(N);
	vector<int> temp(N);
	for (int i = 0; i < N;i++) {
		int num; cin >> num;
		vec[i] = num, temp[i] = num;
		mp[num]++;
	}
	sort(temp.begin(), temp.end());
	int sum = 0, pre = -1;
	for (int i = 0; i < N;i++) if (pre != temp[i]) pre = temp[i],ans[temp[i]] = sum++;
	for (int i = 0; i < N;i++) cout << ans[vec[i]] << " ";
	
	return 0;
}