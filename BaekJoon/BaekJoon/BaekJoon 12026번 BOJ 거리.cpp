#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N;
char arr[1000 + 2];
int cost[1000 + 2];
vector<int> b, o, j;

void DP() {
	for (int pos = 1; pos <= N;pos++) {
		if (arr[pos] == 'B') {
			for (auto now : o)
				if (now > pos) {
					cost[now] = min(cost[now], cost[pos] + (now - pos) * (now - pos));
				}

		}
		else if (arr[pos] == 'O') {
			for (auto now : j)
				if (now > pos){
					cost[now] = min(cost[now], cost[pos] + (now - pos) * (now - pos));
				}
		}
		else if (arr[pos] == 'J'){
			 for (auto now : b){
				 if (now > pos)
					cost[now] = min(cost[now], cost[pos] + (now - pos) * (now - pos));
				}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N;i++) {
		cin >> arr[i];
		if (arr[i] == 'B') b.push_back(i);
		else if (arr[i] == 'O') o.push_back(i);
		else if(arr[i] == 'J') j.push_back(i);
	}
	fill(cost + 1, cost + N + 1, INF);
	cost[1] = 0;
	DP();
	cost[N] == INF ? cout << -1 : cout << cost[N];
	return 0;
}