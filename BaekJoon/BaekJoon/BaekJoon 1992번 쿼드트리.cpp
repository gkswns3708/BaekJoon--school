#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[70][70];
int N;

void dc(int y, int x, int size) {
	char f = arr[y][x];
	if (size == 1) {
		cout << arr[y][x];
		return;
	}
	bool flag = false;
	for (int i = y; i < y + size;i++) {
		for (int j = x; j < x + size;j++) {
			if (arr[i][j] != f) {
				cout << "(";
				dc(y, x, size / 2);
				dc(y, x + size/2, size / 2);
				dc(y+size/2, x, size / 2);
				dc(y + size/2, x + size/2, size / 2);
				cout << ")";
				flag = true;
			}
			if (flag) break;
		}
		if (flag) break;
	}
	if (!flag) cout << arr[y][x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			cin >> arr[i][j];
		}
	}
	dc(0, 0, N);

}