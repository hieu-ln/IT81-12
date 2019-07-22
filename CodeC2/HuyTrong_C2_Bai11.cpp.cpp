//
#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;
void init()
{
	front = NULL;
	rear = NULL;
}
int isEmpty()
{
	if(front==NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node *p;
	p = new Node;
	p->info=x;
	p->link=NULL;
	if(rear == NULL)
		front=p;
	else
		rear->link=p;
	rear=p;
}
int Pop(int &x)
{
	if(front != NULL)
	{
		Node *p=front;
		front=p->link;
		x=p->info;
		if(front==NULL)
			rear=NULL;
		delete p;
		return 1;
	}
	return 0;
}
int main()
{
	int chon,x,y;
	do{
	do{
	cout << "Menu:\n";
	cout << "1.Khoi tao queue rong.\n";
	cout << "2.Xet queue rong.\n";
	cout << "3.Them phan tu vao queue.\n";
	cout << "4.Xoa phan tu trong queue.\n";
	cout << "5.Thoat.\n";
	cout << "Ban chon: ";
	cin >> chon;
	if(chon<1 || chon>5)
		cout << "Chon khong hop le.Chon lai!\n";
	}while(chon<1 || chon>5);
	switch(chon)
	{
	case 1:
		system("cls");
		init();
		cout << "Khoi tao thanh cong!\n";
		break;
	case 2:
		system("cls");
		if(isEmpty()==1)
			cout << "Queue rong!\n";
		else
			cout << "Queue dang co phan tu!.\n";
		break;
	case 3:
		system("cls");
		cout << "Nhap phan tu can them: ";
		cin >> x;
		Push(x);
		cout << "Them thanh cong!\n";
		break;
	case 4:
		system("cls");
		if(Pop(y)==1)
			cout << "Xoa thanh cong!\n";
		else
			cout << "Xoa khong thanh cong!\n";
		break;
	case 5:
		break;
	}
	}while(chon>=1 && chon<5);
	system("pause");
	return 0;
}