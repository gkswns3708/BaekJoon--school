#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 987654321
using namespace std;

int N, R,M,K;
map<string, int> mp;
map<string, int> Transportation;
vector<int> route;
double dist[2][100 + 1][100 + 1];


bool check[100 + 1];

bool floyd_warshall() {
	for (int TC = 0; TC <= 1;TC++) {
		for (int k = 0; k < N;k++) {
			for (int i = 0; i < N;i++) {
				for (int j = 0; j < N;j++) {
					if (dist[TC][i][k] == (double)INF || dist[TC][k][j] == (double)INF)  continue;
					dist[TC][i][j] = min(dist[TC][i][j],dist[TC][i][k] + dist[TC][k][j]);	
				}
			}
		}
	}
	double use = 0, nonuse = 0;
	for (int i = 1; i < M;i++) {
		int from, to;
		from = route[i - 1];
		to = route[i];
		nonuse += dist[0][from][to];
		use += dist[1][from][to];
		//cout << nonuse << " " << use << "-non,use\n";
	}

	//cout << use + (double)R << " " << nonuse<<"-use,nonuse\n";
	return (use + (double)R < nonuse);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> R;
	for (int i = 0; i < N;i++) {
		string s; cin >> s;
		mp.insert({ s,i });
	}
	cin >> M;
	for (int i = 0; i < M;i++) {
		string s; cin >> s;
		route.push_back(mp[s]);
	}
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			if (i == j) {
				dist[0][i][j] = 0;
				dist[1][i][j] = 0;
			}
			else {
				dist[0][i][j] = INF;
				dist[1][i][j] = INF;
			}
		}
	}
	cin >> K;
	for (int i = 0; i < K;i++) {
		string trans, st, ed; double cost; cin >> trans >> st >> ed >> cost;
		dist[0][mp[st]][mp[ed]] = min(dist[0][mp[st]][mp[ed]], cost);
		dist[0][mp[ed]][mp[st]] = min(dist[0][mp[ed]][mp[st]], cost);
		dist[1][mp[st]][mp[ed]] = min(dist[1][mp[st]][mp[ed]], cost);
		dist[1][mp[ed]][mp[st]] = min(dist[1][mp[ed]][mp[st]], cost);
		if (trans == "Mugunghwa" || trans == "ITX-Saemaeul" || trans == "ITX-Cheongchun") 	dist[1][mp[ed]][mp[st]] = dist[1][mp[st]][mp[ed]] = 0;
		else if (trans == "S-Train" || trans == "V-Train") {
			dist[1][mp[st]][mp[ed]] = min(dist[1][mp[st]][mp[ed]], cost / 2);
			dist[1][mp[ed]][mp[st]] = min(dist[1][mp[ed]][mp[st]], cost / 2);
		}
	}



	floyd_warshall() ? cout << "Yes" : cout << "No";
}