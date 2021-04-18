#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int _pow(int x, int p) {
	int ret = 1, piv = x;
	while (p) {
		if (p & 1) ret = ret * piv;
		piv = piv * piv;
		p >>= 1;
	}
	return ret;
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}