#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define pii pair<int,int>
#define int long long
using namespace std;
bool vertical, horizontal;
int pos[4];
typedef struct S_arr{
	int pos, dir;
	int arr[50 + 1][50 + 1];
}S_arr;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, R; cin >> N >> M >> R;

	int arr[100 + 1][100 + 1] = { 0, };
	int temp[4][50 + 1][50 + 1] = { 0, };
	S_arr s_arr[4];
	for (int i = 0; i < N;i++) for (int j = 0; j < M;j++) {
		if (i < N / 2 && j < M / 2) cin >> s_arr[0].arr[i][j];
		else if (i >= N / 2 && j < M / 2) cin >> s_arr[1].arr[i- N/2][j];
		else if (i < N / 2 && j >= M / 2) cin >> s_arr[2].arr[i][j - M/2];
		else if(i >= N / 2 && j >= M / 2) cin >> s_arr[3].arr[i- N/2][j-M/2];
	}
	for (int i = 0; i < 4;i++) {
		pos[i] = i;
		s_arr[i].dir = 0;
	}
	while (R--) {
		int r; cin >> r;
		switch(r) {
			case 1:
				vertical = !vertical;	
				swap(pos[0], pos[2]);
				swap(pos[1], pos[3]);
				break;
			case 2:
				horizontal = !horizontal;
				swap(pos[0], pos[1]);
				swap(pos[2], pos[3]);
				break;
			case 3:
				int tmp = pos[0];
				for (int i = 0; i < 4;i++) {
					pos[i] = pos[(i + 1) % 4];
					s_arr[i].dir = (s_arr[i].dir + 1) % 4;
				}
				pos[3] = tmp;
				break;
			case 4:
				int tmp = pos[3];
				for (int i = 0; i < 4;i++) {
					pos[i] = pos[(i + 3) % 4];
					s_arr[i].dir = (s_arr[i].dir + 3) % 4;
					s_arr[i].pos = (s_arr[i].pos + 3) % 4;
				}
				pos[0] = tmp;
				break;
			case 5:
				for (int i = 0; i < 4;i++) {
					s_arr[i].pos = (s_arr[i].pos + 1) % 4;
				}
				break;
			case 6:
				for (int i = 0; i < 4;i++) {
					s_arr[i].pos = (s_arr[i].pos + 3) % 4;
				}
				break;
		}
	}

	

	for (int n = 0; n < 4;n++) {
		if (vertical) {
			for (int i = 0; i < N / 2;i++)  for (int j = 0; j < M / 2;j++) temp[n][N / 2 - 1 - i][j] = s_arr[n].arr[i][j];
			for (int i = 0; i < N / 2;i++)  for (int j = 0; j < M / 2;j++) s_arr[n].arr[i][j] = temp[n][i][j];
		}
		if (horizontal) {
			for (int i = 0; i < N / 2;i++) 	for (int j = 0; j < M / 2;j++) temp[n][i][N / 2 - 1 - j] = s_arr[n].arr[i][j];
			for (int i = 0; i < N / 2;i++)  for (int j = 0; j < M / 2;j++) s_arr[n].arr[i][j] = temp[n][i][j];
		}
		while(s_arr[n].dir--) rotateR(n);
	}

	

	return 0;
}