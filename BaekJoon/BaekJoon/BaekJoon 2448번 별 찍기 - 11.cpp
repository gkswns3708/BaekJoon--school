#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int N;
char arr[3500][3500];

void reculsive(int y, int x, int size) {
	if (size == 3) {
		for (int i = y; i < y + 3;i++) {
			for(int j = x-2; j <= x + 2;j++) {
				if (i == y && j == x) arr[i][j] = '*';
				else if (i == y + 1 && (j == x-1 || j == x + 1)) arr[i][j] = '*';
				else if (i == y+ 2) arr[i][j] = '*';
			}
		}
		return;
	}
	reculsive(y, x, size / 2);
	reculsive(y + (size / 2), x - (size / 2), size / 2);
	reculsive(y + (size / 2), x + (size / 2), size / 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	fill(&arr[0][0],&arr[3100][3100], ' ');
	reculsive(0,N-1,N);
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < 2 * N;j++) 	cout << arr[i][j];
		cout << '\n';
	}
}