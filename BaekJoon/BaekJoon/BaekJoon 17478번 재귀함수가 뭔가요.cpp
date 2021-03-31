#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
string str[] = {
	"\"����Լ��� ������?\"\n",
	"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
	"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
	"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n",
	"��� �亯�Ͽ���.\n",
	"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n"
};

void recursive(int cnt) {
	if (cnt == n) {
		for (auto now : { 0,5,4 }) {
			for (int i = 0; i < cnt * 4;i++) cout << "_";
			cout << str[now];
		}
		return;
	}
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < cnt * 4;j++) cout << "_";
		cout << str[i];
		if (i == 3) recursive(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursive(0);
	return 0;
}