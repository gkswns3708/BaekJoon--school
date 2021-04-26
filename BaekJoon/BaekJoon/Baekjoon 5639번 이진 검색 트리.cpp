#include <iostream>
#include <vector>
using namespace std;

vector<int> v; //�����ͷ� �Է��� ���ڸ� ���� ����
int cnt = 0; //����� ����

//����� ���� ����ü
typedef struct node {
	int data; //����� ������
	node* left; //�ڱ⺸�� ���� ������ ���� ���� ����� �ּҰ��� ��� ��� ������
	node* right; //�ڱ⺸�� ū ������ ���� ���� ����� �ּҰ��� ��� ��� ������
}node;

node* firstnode; //��Ʈ ��带 ��� ������

void insert(int num) {
	node* newnode = new node[1]; //���ο� ��带 ����

	//���� ������ ����� ������ �ʱ�ȭ, data�� ������ ����, left�� right�� NULL�� �ʱ�ȭ
	newnode->data = num;
	newnode->left = NULL;
	newnode->right = NULL;

	if (cnt == 0) { //����� ������ 0���̸�
		firstnode = newnode; //���� ������ ��尡 ��Ʈ ���� ����
	}
	else { //����� ������ 0���� �ƴϸ�
		node* temp = firstnode;

		//���� ������ ����� ��ġ�� ã�� ����
		while (1) {
			if (temp->data < num) { //�θ��� ���� �ڱ⺸�� ���� ��
				if (temp->right == NULL) { //�θ��� ������ �ڽ��� �ƹ� ��嵵 ������
					temp->right = newnode; //���� ��带 �θ��� ������ �ڽ����� ����
					break; //Ż��
				}
				temp = temp->right; //�θ��� ������ �ڽ����� �̵�
			}
			else if (temp->data > num) { //�θ��� ���� �ڱ⺸�� Ŭ ��
				if (temp->left == NULL) { //�θ��� ���� �ڽ��� �ƹ� ��嵵 ������
					temp->left = newnode; //���� ��带 �θ��� ���� �ڽ����� ����
					break; //Ż��
				}
				temp = temp->left; //�θ��� ���� �ڽ����� �̵�
			}
		}
	}
	cnt++; //����� ���� ����
	return;
}

//����Ž������
void postorder(node* temp) {
	if (temp) { //NULL�����͸� ������ ������
		postorder(temp->left); //���� �ڽ����� �̵�
		postorder(temp->right); //������ �ڽ����� �̵�
		cout << temp->data << '\n'; //���� ����� ������ ���
	}
}

int main() {
	int num; //�����ͷ� �Է��� ����

	//EOF�� ������ ������ �Է�
	while (cin >> num) {
		v.push_back(num);
	}

	//������ �����س��� ���ڸ� ����� �����ͷ� ����
	for (int i = 0; i < v.size(); i++) {
		insert(v[i]);
	}

	postorder(firstnode); //����Ž������
}