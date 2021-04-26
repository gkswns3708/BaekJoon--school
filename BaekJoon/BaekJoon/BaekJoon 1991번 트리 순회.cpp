#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef struct Node {
	int num;
	Node* left;
	Node* right;
	int parents = -1;
}Node;

Node node[26 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N;i++) {
		char parents, left, right; 
		cin >> parents >> left >> right;
		node[parents - 'A'].num = parents - 'A';
		
		if (left != '.') {
			node[parents - 'A'].left = &node[left - 'A'];
			node[left - 'A'].parents = parents - 'A';
		}
		if (right != '.') {
			node[right - 'A'].parents = parents - 'A';
			node[parents - 'A'].right = &node[right - 'A'];
		}
	}

	int root = -1;
	for (int i = 0; i < N;i++) if (node[i].parents == -1) root = i;
	function <void(Node *)> PreOrder = [&](Node* now)-> void{
		cout << (char)(now->num + 'A');
		if (now->left != nullptr) 	PreOrder(now->left);
		if (now->right != nullptr) PreOrder(now->right);
	};
	function <void(Node*)> InOrder = [&](Node* now)-> void {
		if (now->left != nullptr) 	InOrder(now->left);
		cout << (char)(now->num + 'A');
		if (now->right != nullptr) InOrder(now->right);
	};
	function <void(Node*)> PostOrder = [&](Node* now)-> void {
		if (now->left != nullptr) 	PostOrder(now->left);
		if (now->right != nullptr) PostOrder(now->right);
		cout << (char)(now->num + 'A');
	};

	PreOrder(&node[root]);
	cout << "\n";
	InOrder(&node[root]);
	cout << "\n";
	PostOrder(&node[root]);
	return 0;
}