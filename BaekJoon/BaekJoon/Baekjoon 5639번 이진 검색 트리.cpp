#include <iostream>
#include <vector>
using namespace std;

vector<int> v; //데이터로 입력할 숫자를 담을 벡터
int cnt = 0; //노드의 갯수

//노드의 대한 구조체
typedef struct node {
	int data; //노드의 데이터
	node* left; //자기보다 작은 데이터 값을 가진 노드의 주소값을 담는 노드 포인터
	node* right; //자기보다 큰 데이터 값을 가진 노드의 주소값을 담는 노드 포인터
}node;

node* firstnode; //루트 노드를 담는 포인터

void insert(int num) {
	node* newnode = new node[1]; //새로운 노드를 생성

	//새로 삽입한 노드의 정보를 초기화, data는 삽입한 숫자, left와 right는 NULL로 초기화
	newnode->data = num;
	newnode->left = NULL;
	newnode->right = NULL;

	if (cnt == 0) { //노드의 갯수가 0개이면
		firstnode = newnode; //지금 삽입한 노드가 루트 노드로 지정
	}
	else { //노드의 갯수가 0개가 아니면
		node* temp = firstnode;

		//현재 삽입한 노드의 위치를 찾는 과정
		while (1) {
			if (temp->data < num) { //부모의 값이 자기보다 작을 때
				if (temp->right == NULL) { //부모의 오른쪽 자식의 아무 노드도 없으면
					temp->right = newnode; //현재 노드를 부모의 오른쪽 자식으로 삽입
					break; //탈출
				}
				temp = temp->right; //부모의 오른쪽 자식으로 이동
			}
			else if (temp->data > num) { //부모의 값이 자기보다 클 때
				if (temp->left == NULL) { //부모의 왼쪽 자식의 아무 노드도 없으면
					temp->left = newnode; //현재 노드를 부모의 왼쪽 자식으로 삽입
					break; //탈출
				}
				temp = temp->left; //부모의 왼쪽 자식으로 이동
			}
		}
	}
	cnt++; //노드의 갯수 증가
	return;
}

//후위탐색실현
void postorder(node* temp) {
	if (temp) { //NULL포인터를 만나기 전까지
		postorder(temp->left); //왼쪽 자식으로 이동
		postorder(temp->right); //오른쪽 자식으로 이동
		cout << temp->data << '\n'; //현재 노드의 데이터 출력
	}
}

int main() {
	int num; //데이터로 입력할 숫자

	//EOF를 만나기 전까지 입력
	while (cin >> num) {
		v.push_back(num);
	}

	//벡터의 저장해놓은 숫자를 노드의 데이터로 삽입
	for (int i = 0; i < v.size(); i++) {
		insert(v[i]);
	}

	postorder(firstnode); //후위탐색실현
}