#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


int solution(vector<string> lines) {
	int answer = 0;
	vector<vector<int>> vec((int)lines.size(), vector<int>());
	for (int i = 0; i < lines.size();i++) {
		for (auto& now : lines[i]) if (now == '-' || now == '.'|| now == ':') now = ' ';
		string num;
		stringstream ss;
		ss << (lines[i]);
		int cnt = 0;
		while (ss >> num) {
			if (num.back() == 's' && cnt == 8) {
				num.pop_back();
				while (num.size() < 3) num += '0';
			}
			vec[i].push_back(stoi(num));
			cnt++;
		}
		for (auto now : vec[i]) cout << now << " ";
		cout << "\n";
	}

	vector<pair<int, int>> times;
	for (auto now : vec) {
		int st, ed;
		if (now.size() == 9) st = now[3] * 3600 * 1000 + now[4] * 60 * 1000 + now[5] * 1000 + now[6] - (now[7] * 1000 + now[8] - 1);
		else				 st = now[3] * 3600 * 1000 + now[4] * 60 * 1000 + now[5] * 1000 + now[6] - (now[7] * 1000 - 1);
							 ed = now[3] * 3600 * 1000 + now[4] * 60 * 1000 + now[5] * 1000 + now[6];
		times.push_back({ st,ed });
	}
	for (auto now : times) {
		auto [st, ed] = now;
		int cnt1 = 0, cnt2 = 0;
		for (auto nnow : times) {
			//if (nnow.first >= st && nnow.first <= st + 999 || nnow.second >= st && nnow.second <= st + 999) cnt1++;
			//if (nnow.first >= ed && nnow.first <= ed + 999 || nnow.second >= ed && nnow.second <= ed + 999) cnt2++;
			if (nnow.first <= st + 999 && nnow.second >= st) cnt1++;
			if (nnow.first <= ed + 999 && nnow.second >= ed) cnt2++;
		}
		answer = max({ answer,cnt1,cnt2 });
	}
	
	return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<string> lines = {
		"2016-09-15 20:59:57.421 0.351s",
	"2016-09-15 20:59:58.233 1.181s",
	"2016-09-15 20:59:58.299 0.8s",
	"2016-09-15 20:59:58.299 1s",
	"2016-09-15 20:59:58.688 1.041s",
	"2016-09-15 20:59:59.591 1.412s",
	"2016-09-15 21:00:00.464 1.466s",
	"2016-09-15 21:00:00.741 1.581s",
	"2016-09-15 21:00:00.748 2.31s",	
	"2016-09-15 21:00:00.966 0.381s",
	"2016-09-15 21:00:02.066 2.62s"
	};
	cout << solution(lines);
	return 0;
}
