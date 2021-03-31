#include <iostream>
#include <regex>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--){
		string a, b; cin >> a >> b;
		int cnt = 0; char ans = ' ';
		for (int i = 0; i < 26; i++){
			char c = 'A' + i;
			string s = a;
			s[s.find('_')] = c;
			regex r(s);
			if (regex_match(b, r)) {
				cnt++;
				ans = c;
			}
		}
		if (cnt == 0) cout << "!\n";
		else if (cnt == 1) cout << ans << "\n";
		else cout << "_\n";
	}
}