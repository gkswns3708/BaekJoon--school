#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vec;
int cnt = 0;

typedef struct node {
	int data;
	node* left;
	node* right;
}node;

node* firstnode;

void insert(int num) {
	node* newnode = new node[1];
	
	newnode->data = num;
	newnode->left = NULL;
	newnode->right = NULL;

	if (cnt == 0) firstnode = newnode;
	else {
		node* temp = firstnode;

		while (1) {
			if (temp->data < num) {
				if (temp->right == NULL) {
					temp->right = newnode;
					break;
				}
				temp = temp->right;
			}
			else if (temp->data > num) {
				if (temp->left == NULL) {
					temp->left = newnode;
					break;
				}
				temp = temp->left;
			}
		}
	}
	cnt++;
	return;
}

void postorder(node* temp) {
	if (temp) { //NULL�����͸� ������ ������
		postorder(temp->left); //���� �ڽ����� �̵�
		postorder(temp->right); //������ �ڽ����� �̵�
		cout << temp->data << '\n'; //���� ����� ������ ���
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num; 
	while (cin >> num) vec.push_back(num),insert(num);
	postorder(firstnode);
	return 0;
}