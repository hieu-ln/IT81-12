//
#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int front,rear;
void init(int a[],int &front,int &rear)
{
	front = -1;
	rear = -1;
}
void isEmpty(int a[],int front,int rear)
{
	if(front==-1 && rear==-1)
		cout << "Hang doi rong\n";
	else
		cout << "Hang doi dang co phan tu.\n";
}
void isFull(int a[],int front, int rear)
{
	if(rear - front == MAX -1)
		cout << "Hang doi day\n";
	else
		cout << "Hang doi chua day\n";
}
int Push(int a[],int &front,int &rear,int x)
{
	if(rear - front ==MAX -1)
		return 0;
	else
	{
		if(front == -1)
			front=0;
		if(rear == MAX -1)
		{
			for(int i=front;i<=rear;i++)
				a[i-front]=a[i];
			rear=MAX -1-front;
			front=0;
		}
		a[++rear]=x;
		return 1;
	}
}
int Pop(int a[],int &front,int &rear,int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x=a[front++];
		if(front > rear)
		{
			front=-1;
			rear=-1;
		}
		return 1;
	}
}
int main()
{
	int chon,x,y;
	do{
	do{
	cout << "Menu:\n";
	cout << "1.Khoi tao queue rong.\n";
	cout << "2.Xet queue rong.\n";
	cout << "3.Xet queue day.\n";
	cout << "4.Them 1 phan tu vao queue.\n";
	cout << "5.Xoa 1 phan tu trong queue.\n";
	cout << "6.Thoat.\n";
	cout << "Ban chon: ";
	cin >> chon;
	if(chon<1 || chon >6)
		cout << "Chon khong phu hop.Chon lai!\n";
	}while(chon<1 || chon >6);
	switch(chon)
	{
	case 1:
		system("cls");
		init(a,front,rear);
		cout << "Khoi tao thanh cong!\n";
		break;
	case 2:
		system("cls");
		isEmpty(a,front,rear);
		break;
	case 3:
		system("cls");
		isFull(a,front,rear);
		break;
	case 4:
		system("cls");
		cout << "Nhap phan tu muon them: ";
		cin >> x;
		if(Push(a,front,rear,x)==0)
			cout << "Them khong thanh cong.\n";
		else
			cout << "Them thanh cong.\n";
		break;
	case 5:
		system("cls");
		if(Pop(a,front,rear,y)==0)
			cout << "Xoa phan tu khong thanh cong.\n";
		else
			cout << "Xoa thanh cong.\n";
		break;
	case 6:
		system("cls");
		break;
	}
	}while(chon>=1 && chon<6);
	system("pause");
	return 0;
}