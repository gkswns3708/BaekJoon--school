#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days(progresses.size());
	for (int i = 0; i < progresses.size();i++) {
		days[i] = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i]) days[i]++;
	}
	queue<int> que;
	for (auto now : days) que.push(now);
	int maxvalue = que.front();
	int cnt = 1;
	int pushpos = -1;
	que.pop();
	while (!que.empty()) {
		if (que.front() > maxvalue) {
			answer.push_back(cnt);
			maxvalue = que.front();
			cnt = 1;
			que.pop();
		}
		else {
			cnt++;
			que.pop();
		}
	}
	answer.push_back(cnt);
	//for (auto now : answer) cout << now << " ";
    return answer;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N,M; cin >> N;
	vector<int> progresses(N);
	vector<int> speeds(N);
	for (int i = 0; i < N;i++) cin >> progresses[i];
	for (int i = 0; i < N;i++) cin >> speeds[i];

	solution(progresses, speeds);

	return 0;
}