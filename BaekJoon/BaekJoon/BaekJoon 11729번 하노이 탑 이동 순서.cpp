#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void move(int st, int to) {
	cout << st << " " << to << "\n";
}

void hanoi( int end, int st, int by, int to) {
	if (end == 1) move(st, to);
	else {
		hanoi(end - 1, st, to, by);
		move(st, to);
		hanoi(end - 1, by, st, to);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int num = (1 << N )- 1;
	cout << num << "\n";
	hanoi(N, 1, 2, 3);
	return 0;
}