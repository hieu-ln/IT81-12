// Bai 1, Chuong 4, Cay nhi phan tim kiem
#include<iostream>
#include<stdlib.h>
using namespace std;

#define COUNT 10
//Cau 1.1 Khai bao cau truc cay NPTK
struct Node 
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
//Cau 1.2 Khoi tao cay rong
void Init()
{
	root = NULL;
}
//Cau 1.3 Them mot phan tu su dung de quy
void InsertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
			if (x>p->info)
				return InsertNode(p->right, x);
			else
				return InsertNode(p->left, x);
	}
}
//Cau 1.4 Tim mot phan tu su dung de quy
Node *search(Node *p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x>p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;

}
//Cau 1.5 Xoa mot nut trong cay dung de quy
void searchandfor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p -> info = q->info;
		p = q;
		q = q -> right;
	}
	else
		searchandfor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if (T == NULL) return 0;
	if (T ->info == x)
	{
		Node *p = T;
		if (T -> left == NULL)
			T = T -> right;
		else if (T -> right == NULL)
			T = T ->left;
		else
			searchandfor(p, T -> right);
		delete p;
		return 1;
	}
	if (T -> info < x) return Delete(T->right, x);
	if (T -> info < x) return Delete(T->left, x);
}
//Cau 1.6 Duyet cay theo NLR dung de quy
void DuyetLNR(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p -> info << " ";
		DuyetLNR(p -> right);
	}
}
//Cau 1.7 Duyet cay theo NLR dung de quy
void DuyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p -> info << " ";
		DuyetNLR(p->left);
		DuyetNLR(p -> right);
	}
}

//Cau 1.8 Duyet cay theo LRN dung de quy
void DuyetLRN(Node *p)
{
	if (p != NULL)
	{
		DuyetLRN(p -> right);
		DuyetLRN(p->left);
		cout << p -> info << " ";
	}
}
void print2DUtil(Node *p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	print2DUtil(p -> right, space);
	cout << endl;
	for ( int i = COUNT; i < space; i++)
		cout << " ";
	cout << p-> info << "\n";
	print2DUtil(p -> left, space);

}
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "-------------Bai tap 1, Chuong 4, Cay NPTK----------" << endl;
	cout << "1.Khoi tao cay NPTK rong" << endl;
	cout << "2.Them phan tu vao cay NPTK " << endl;
	cout << "3.Tim phan tu co gia tri x trong cay NPTK " << endl;
	cout << "4.Xoa phan tu co gia tri x trong cay NPTK " << endl;
	cout << "5.Duyet cay NPTK theo LNR " << endl;
	cout << "6.Duyet cay NPTK theo NLR " << endl;
	cout << "7.Duyet cay NPTK theo LRN " << endl;
	cout << "8.Xuat cay NPTK " << endl;
	cout << "9.Thoat " << endl;
	do
	{
		cout << "Vui long chon so thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Init();
				cout << "Khoi tao cay thanh cong" << endl;
				break;
			case 2:
				cout << "Vui long nhap x can them: ";
				cin >> x;
				InsertNode(root, x);
				cout << "Cay NPTK sau khi them la: ";
				Process_Tree();
				break;
			case 3:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				p = search(root, x);
				if (p!=NULL)
					cout << "Tim thay x= " << x << endl;
				break;
			case 4:
				cout << "Vui long nhap x can xoa: ";
				cin >> x;
				i = Delete(root, x);
				if (i == 0)
					cout << "Khong tim thay x "<< endl;
				else
				{
					cout << "Da xoa thanh cong x=" << x << endl;
					cout << "Cay NPTK sau khi xoa la: ";
					Process_Tree();
				}
				break;
			case 5:
				cout << "Cay NPTK duyet theo LRN la: ";
				DuyetLRN(root);
				break;
			case 6:
				cout << "Cay NPTK duyet theo NLR la: ";
				DuyetNLR(root);
				break;
			case 7:
				cout << "Cay NPTK duyet theo LNR la: ";
				DuyetLNR(root);
				break;
			case 8:
				cout << "Cay NPTK la: ";
				Process_Tree();
				break;
			case 9:
				cout << "Bye" << endl;
			default:
				break;
		}
	}while (choice!=9);
	system("pause");
	return 0;
}
