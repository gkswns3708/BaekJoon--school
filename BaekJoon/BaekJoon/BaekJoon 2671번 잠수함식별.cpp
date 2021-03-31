#include <iostream>
#include <regex>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	regex r(R"((100+1+|01)+)");
	string s; cin >> s;
	regex_match(s, r) ? cout << "SUBMARINE" : cout << "NOISE";
	return 0;
}