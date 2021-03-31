#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vec;
vector<int> flag;
int cnt = 0;
void DFS(int sum, int sign, int num,int pos, string str) {
	if (pos == N) {
		sum += (num * sign);
		if (sum == 0) cout << str << "\n";
		return;
	}
	else {
		DFS(sum, sign, num * 10 + (pos + 1), pos + 1, str +' '+ char(pos+1+'0'));
		DFS(sum + (sign * num), 1, pos + 1, pos + 1, str + '+' + char(pos + 1 + '0'));
		DFS(sum + (sign * num), -1, pos + 1, pos + 1, str + '-' + char(pos + 1 + '0'));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		cin >> N;
		DFS(0, 1, 1, 1, "1");
		cout << "\n";
	}
}