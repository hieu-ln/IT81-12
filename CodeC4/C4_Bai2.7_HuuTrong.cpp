#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
#define count 10
struct node
{
	int info;
	node *left, *right;
};
node *root;
void tree_empty()
{
	root = NULL;
}
void insertnode(node *&p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return;
		else
			if (p->info > x)
				return insertnode(p->left, x);
			else
				return insertnode(p->right, x);
	}
	else {
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
}
//them node ko can dia chi
int insert(node *p, int x)
{
	if (p->info == x)
		return 0;
	else
		if (p->info > x)
		{
			if (p->left == NULL)
			{
				node *y = new node;
				y->info = x;
				y->left = NULL;
				y->right = NULL;
				p->left = y;
				return 1;
			}
			else return insert(p->left, x);
		}
		else {
			if (p->right == NULL)
			{
				node *y = new node;
				y->info = x;
				y->left = NULL;
				y->right = NULL;
				p->right = y;
				return 1;
			}
			else return insert(p->right, x);
		}
}
node *seach(int x)
{
	node *p = root;
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				p = p->left;
			else
				p = p->right;
	}
	return NULL;
}
void seachstandfor(node *&p, node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		seachstandfor(p, q->left);
}
int deletenode(node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				seachstandfor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return deletenode(T->right, x);
	if (T->info > x)
		return deletenode(T->left, x);
}

void duyetLNR(node *p)
{
	stack<node*> s;
	p = root;
	while (p != NULL || s.empty() == false)
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		cout << setw(4) << p->info;
		p = p->right;
	}
}
void print(node *p, int space)
{
	if (p == NULL)
		return;
	space += count;
	print(p->right, space);
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left, space);
}
void process_print()
{
	print(root, 0);
}
int dem(node *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + dem(p->left) + dem(p->right);
}
int main()
{
	int x, chon;
	char tt;
	do {
		system("cls");
		cout << "1. Khoi tao cay rong\n"
			<< "2. Them phan tu vao cay\n"
			<< "3. Duyet cay theo thu tu LNR\n";
		cout << "Chon de thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			tree_empty();
			cout << "Khoi tao thanh cong!!!";
			break;
		case 2:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			insertnode(root, x);
			cout << "Cay nhi phan dang luu tru: ";
			process_print();
			break;
		case 3:
			cout << "Ket qua duyet LNR: ";
			duyetLNR(root);
			break;
		}
		cout << endl;
		cout << "Ban co muon tiep tuc (Y/N): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
}