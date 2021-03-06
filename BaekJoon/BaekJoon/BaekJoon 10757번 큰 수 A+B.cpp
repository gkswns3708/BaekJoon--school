#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	string temp = "";
	int len1 = s1.length(), len2 = s2.length();
	int gap = max(len1, len2) - min(len1, len2);
	for (int i = 0; i < gap;i++) temp.push_back('0');
	if (len1 > len2) temp += s2,s2 = temp;
	else temp += s1, s1 = temp;
	bool flag = false;
	vector<int> ans(max(len1, len2));
	for (int i = temp.size()-1; i >= 0;i--) {
		int num = s1[i] + s2[i] - '0' - '0' + flag;
		if (num >= 10) flag = 1,ans[i] = num-10;
		else flag = 0, ans[i] = num;
	}
	if (flag) cout << 1;
	for (auto now : ans) cout << now;
	return 0;
}