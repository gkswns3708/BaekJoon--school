#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<int> arr;
vector<int> input_arr;
vector<int> visit;
vector<vector<int>> save_visit;

void recursive(int arr_size, vector<int> arr, int j, vector<int> visit) {
    arr.push_back(input_arr[j]);

    if (arr.size() == M) {
        for (int i = 0; i < save_visit.size(); i++) {
            if (save_visit[i] == arr) return;
        }
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        save_visit.push_back(arr);
        return;
    }
    visit.push_back(j);
    for (int i = 0; i < N; i++) {
        bool isVisit = false;
        for (int j = 0; j < visit.size(); j++) {
            if (visit[j] == i) isVisit = true;
        }
        if (!isVisit) {
            recursive(arr_size + 1, arr, i, visit);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        input_arr.push_back(input);
    }
    sort(input_arr.begin(), input_arr.end());
    for (int i = 0; i < N; i++) {
        recursive(i, arr, i, visit);
    }

    return 0;
}