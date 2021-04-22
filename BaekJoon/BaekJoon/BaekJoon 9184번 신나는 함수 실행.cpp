#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int value[50 + 1][50 + 1][50 + 1];

int reculsive(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (value[a][b][c] != -1) return value[a][b][c];
	if (a > 20 || b > 20 || c > 20) return value[a][b][c] = reculsive(20, 20, 20);
	if (a < b && b < c)	return value[a][b][c] = reculsive(a, b, c - 1) + reculsive(a, b - 1, c - 1) - reculsive(a, b - 1, c);
	else return value[a][b][c] = reculsive(a - 1, b, c) + reculsive(a - 1, b - 1, c) + reculsive(a - 1, b, c - 1) - reculsive(a - 1, b - 1, c - 1);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	for (int i = 0; i < 51;i++) for (int j = 0; j < 51;j++) for (int k = 0; k < 51;k++)
		value[i][j][k] = -1;
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1)return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << reculsive(a, b, c)<<"\n";
	}
}