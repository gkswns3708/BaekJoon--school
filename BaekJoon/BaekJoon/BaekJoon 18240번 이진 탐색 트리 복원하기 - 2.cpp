#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

vector<int> height[300000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int mh = -1;
	vector<int> ans(N+1);
	height[0].push_back(1);
	for (int i = 2; i <= N;i++) {
		int level; cin >> level;
		mh = max(mh, level);
		int num = i;
		height[level].push_back(i);
		if (height[level - 1].size() * 2 < height[level].size()) {
			cout << -1;
			exit(0);
		}
		//for (int j = 0; j <= mh;j++) {
		//	for (auto now : height[j]) 
		//		cout << now << " ";
		//	cout << "\n";
		//}
		//cout << "\n";
	}
	int cnt = 1;
	function <void(int, int)> preorder = [&](int level,int pos)->void {
		if (pos * 2 <= (int)(height[level + 1].size())-1) preorder(level + 1, pos * 2);
		cout << level << " " << pos << " " <<" " << height[level][pos] <<" "<< cnt << "-level,pos,cnt\n";
		ans[height[level][pos]] = cnt++;
		if (pos * 2 + 1 <= (int)height[level + 1].size() - 1) preorder(level + 1, pos * 2 + 1);
	};
	preorder(0, 0);
	for (auto now : ans) cout << now << " ";
	return 0;
}