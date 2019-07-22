//
#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int sp;
void init(int a[],int &sp)
{
	sp=-1;
}
int isFull(int a[],int sp)
{
	if(sp == MAX-1)
		return 1;
	return 0;
}
int isEmpty(int a[],int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
int Push(int a[],int &sp,int x)
{
	if(sp < MAX-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;	
}
int Pop(int a[],int &sp,int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}
int main()
{
	int chon,x,y;
	do{
	cout << "Menu:\n";
	cout << "1.Khoi tao stack rong.\n";
	cout << "2.Xet stack rong.\n";
	cout << "3.Xet stack day.\n";
	cout << "4.Them 1 phan tu vao stack.\n";
	cout << "5.Xoa phan tu trong stack.\n";
	cout << "6.Thoat.\n";
	cout << "Ban chon: ";
	do{
	cin >> chon;
	if(chon < 1|| chon > 6)
		cout << "Chon khong thich hop.Chon lai: ";
	}while(chon < 1|| chon > 6);
	switch (chon)
	{
	case 1:
		system("cls");
		init(a,sp);
		cout << "Khoi tao stack rong thanh cong!\n";
		break;
	case 2:
		system("cls");
		if(isEmpty(a,sp)==-1)
			cout << "Danh sach dang rong\n";
		else
			cout << "Danh sach dang co phan tu\n";
		break;
	case 3:
		system("cls");
		if(isFull(a,sp)==1)
			cout << "Danh sach da day\n";
		else
			cout << "Danh sach chua day\n";
		break;
	case 4:
		system("cls");
		cout << "Nhap pha ntu muon them vao stack: ";
		cin >> x;
		if(Push(a,sp,x)==1)
			cout << "Ban da them thanh cong!\n";
		else
			cout << "Them khong thanh cong!\n";
		break;
	case 5:
		system("cls");
		cout << "Nhap phan tu muon xoa: ";
		cin >> y;
		if(Pop(a,sp,y)==1)
			cout << "Xoa thanh cong!\n";
		else
			cout << "Xoa khong thanh cong!\n";
		break;
	case 6:
		system("cls");
		break;
	}
	}while(chon>=1 && chon <6);
	system("pause");
	return 0;
}