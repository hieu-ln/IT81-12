//
#include<iostream>
using namespace std;
struct Node{
	int info;
	Node *link;
};
Node *sp;
void init()
{
	sp=NULL;
}
int isEmpty()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}
int Pop(int &x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
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
	cout << "1.Khoi tao stack rong.\n";
	cout << "2.Xet stack rong.\n";
	cout << "3.Them phan tu vao stack.\n";
	cout << "4.Xoa phan tu khoi stack.\n";
	cout << "5.Doi so he thap phan sang he nhi phan.\n";
	cout << "6.Giai bai toan thap Ha Noi.\n";
	cout << "7.Thoat.\n";
	cout << "Ban chon: ";
	cin >> chon;
	if(chon < 1 || chon > 7)
		cout << "Nhap khong thich hop.Nhap lai!!\n";
	}while(chon < 1 || chon > 7);
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
			cout << "Stack rong!\n";
		else
			cout << "Stack co phan t!\n";
		break;
	case 3:
		system("cls");
		cout << "Nhap phan tu muon them vao stack: ";
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
	case 6:
		break;
	case 7:
		break;
	}
	}while(chon>=1 && chon<7);
	system("pause");
	return 0;
}