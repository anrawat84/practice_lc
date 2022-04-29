#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

#define MAX 10
#define lt 0
#define rt 1

using namespace std;
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *getnode(int elem)
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	tmp->data = elem;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void make_tree(NODE **head, int *arr, int len)
{
	*head = getnode(arr[0]);
	NODE *tmp = *head, *prev = NULL;
	bool pos;
	for (int i = 1; i < len; i++) {
		tmp = *head;
		while (tmp) {
			if (arr[i] < tmp->data) {
				prev = tmp;
				pos = lt;
				tmp = tmp->left;
			} else if (arr[i] > tmp->data) {
				prev = tmp;
				pos = rt;
				tmp = tmp->right;
			}
		}
		if (pos == lt) {
			prev->left = getnode(arr[i]);
		} else prev->right = getnode(arr[i]);
	}
}

void traverse_inorder(NODE *head)
{
	if (!head) {
		return;
	}
	traverse_inorder(head->left);
	cout << head->data << "  ";
	traverse_inorder(head->right);
}

void dfs_traversal(NODE *head)
{
	stack <NODE *> st;
	cout << endl;
	cout <<  head->data << "  ";
	if (head->right) {
		st.push(head->right);
	}
	if (head->left) {
		st.push(head->left);
	}
	while (!st.empty()) {
		NODE *tmp = st.top();
		st.pop();
		cout << tmp->data << " ";
		if (tmp->right) st.push(tmp->right);
		if (tmp->left) st.push(tmp->left);
	}
}

void dfs_traversal_rev(NODE *head)
{
	stack <NODE *> st;
	cout << endl;
	cout <<  head->data << "  ";
	if (head->left) {
		st.push(head->left);
	}
	if (head->right) {
		st.push(head->right);
	}
	while (!st.empty()) {
		NODE *tmp = st.top();
		st.pop();
		cout << tmp->data << " ";
		if (tmp->left) st.push(tmp->left);
		if (tmp->right) st.push(tmp->right);
	}
}
int main()
{
	NODE *head = NULL;
	int arr[] = {6, 5, 17, 29,1, 10, 100};
	int len = sizeof(arr)/sizeof(arr[0]);
	make_tree(&head, arr, len);
	cout << endl;
	traverse_inorder(head);
	cout << endl;
	dfs_traversal(head);
	cout << endl;
	dfs_traversal_rev(head);
	cout << endl;
	return 0;
}
