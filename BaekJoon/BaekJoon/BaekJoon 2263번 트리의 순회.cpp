#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> postorder(N + 1), inorder(N + 1), index(N + 1);
	for (int i = 0; i < N;i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 0; i < N;i++) cin >> postorder[i];

	function <void (int, int,int ,int)> maketree = [&](int pst, int ped, int ist, int ied)->void {
		//cout <<pst <<" " << ped << "-ed\n";
		if (pst > ped || ist > ied) return;
		int root = postorder[ped];
		cout << root << " ";

		maketree(pst, pst + (index[root] - ist )-1, ist, index[root] - 1);
		maketree(pst + (index[root] - ist), ped - 1, index[root] + 1, ied);

	};
	maketree(0, N - 1, 0, N - 1);
	return 0;
}