#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

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
	NODE *tmp = *head;
	for (int i = 1; i < len; i++) {
		while (tmp) {
			if (arr[i] < tmp->data) {
				prev = tmp;
				left = true;
				tmp = tmp->left;
			} else if (arr[i] > tmp->data) {
				prev = tmp;
				right = true;
				tmp = tmp->right;
			}
		}
		if (left == true) {
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

int main()
{
	NODE *head = NULL;
	int arr[] = {6, 5, 17, 29,1, 10, 100};
	int len = sizeof(arr)/sizeof(arr[0]);
	make_tree(&head, arr, len);
	traverse_inorder(head);
	return 0;
}
