#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[3000][3000];

void print(int y,int x,int size) {
	if (size == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) continue;
				arr[y + i][x + j] = '*';
			}
		}
	}
	else {
		size /=3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) continue;
				else print(y + size * i, x + size * j, size);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	fill(&arr[0][0], &arr[3000-10][3000-10], ' ');
	print(0,0,N);
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}