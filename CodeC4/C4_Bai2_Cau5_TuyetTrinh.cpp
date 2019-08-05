#include <iostream>
#include <stdio.h>
using namespace std;
#define COUNT 10
//cau 2.1
struct Node
{
	int info;
	Node* left;
	Node* right;
};
Node* root;
//cau 2.2
void tree_empty()
{
	root = NULL;
}
// ham searchStandFor
void searchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
//cau 2.5
int Delete(Node*& T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}
// xuat
void print2DUtil(Node* p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	print2DUtil(p->left, space);
}
// Wrapper over print2DUtil()
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int x, i;
	cout << "Vui Long nhap gia tri x can xoa: ";
	cin >> x;
	i = Delete(root, x);
	if (i == 0)
		cout << "Khong tim thay x = " << x << " de xoa\n";
	else
	{
		cout << "Da xoa thnah cong phan tu x = " << x << "trong cay NPTK\n";
		cout << " NPTK sau khi xoa la: \n";
		Process_Tree();
	}
	system("pause");
	return 0;
}