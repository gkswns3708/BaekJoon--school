#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
using namespace std;
int N;
vector<int> vec;
bool flag = 0;
bool possible() {
	for (int i = 1; i <= vec.size() / 2;i++) {
		string s1, s2;
		for (int j = 0; j < i;j++) 	s1.push_back(vec[vec.size() - i * 2 + j]), s2.push_back(vec[vec.size() - i + j]);
		if (s1 == s2) return false;
	}
	return true;
}

void BP (int cnt) {
	if (cnt == N) {
		for (auto now : vec)  cout << now;
		exit(0);
	}

	for (int i = 1; i <= 3;i++) {
		vec.push_back(i);
		if (possible()) BP(cnt + 1);
		vec.pop_back();
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	BP(0);

	return 0;
}