#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int TC = 1; ; TC++) {
		set<int> st;
		int from, to, cnt = 0;
		bool flag = false;
		for (int i = 0; ; i++){
			cin >> from >> to;
			if (i == 0) {
				if (from == -1 && to == -1) exit(0);
				else if (from == 0 && to == 0) {
					cout << "Case " << TC << " is a tree.\n";
					flag = true;
				}
			}
			if (from == 0 && to == 0) break;
			st.insert(from), st.insert(to);
			cnt++;
		}
		if(!flag) cnt + 1 == st.size() ? cout << "Case " << TC << " is a tree.\n" : cout << "Case " << TC << " is not a tree.\n";
	}
}