#include<iostream>
#include <stdio.h>
using namespace std;
//4.1
struct Node
{
	int info;
	Node* link;
};
Node* first;
//cau 4.2
void init()
{
	first = NULL;
}
//cau 4.3
void Insert(int x)
{
	Node* p, * q, * a;
	p = new Node;
	p->info = x;
	q = first;
	a = first;
	while (q != NULL && q->info < x)
	{
		a = q;
		q = q->link;
	}
	if (q == first)
		first = p;
	else
		a->link = p;
	p->link = q;
}
//cau4.4
void Process_list()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->info << "	";
		p = p->link;
	}
	cout << endl;
}
//cau 4.5
Node *Search(int x)
{
	Node* p = first;
	while (p->link != NULL && p->info != x)
		p = p->link;
	return p;
}
//cau 4.6
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if (p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				if (p->link == NULL && p->info == x)
				{
					q->link = NULL;
					delete p;
					return 1;
				}
				else
					return 0;
	}
	return 0;
}

int main()
{
	int choice, x, i;
	Node* a;
	system("cls");
	cout << "-------MENU------\n";
	cout << "1. Khoi tao danh sach rong\n";
	cout << "2. Them phan tu vao danh sach\n";
	cout << "3. Tim mot phan tu trong danh sach\n";
	cout << "4. Tim va xoa mot phan tu trong danh sach\n";
	cout << "6. Xuat danh sach\n";
	cout << "7. Thoat\n";
	do {
		cout << "Vui long chon de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao danh sach rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout << "Nhap vao gia tri can tim x = ";
			cin >> x;
			a = Search(x);
			if (a == NULL)
				cout << "Gia tri x = " << x << " khong co trong mang\n";
			else
				cout << "Tim thay gia ti x = " << x << " o vi tri " << a << endl;
			break;
		case 4:
			cout << "Nhap vao gia tri can tim x = ";
			cin >> x;
			i = SearchAndDelete(x);
			if (i == 0)
				cout << "Khong tim thay x = " << x << endl;
			else
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong\n";
				cout << "Danh sach sau  khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			cout << "Danh sach sau hien tai la: ";
			Process_list();
			break;
		case 6:
			cout << "Goodbye!!!\n";
			break;
		default:
			break;
		}
	} while (choice < 6);
	system("pause");
	return 0;
}