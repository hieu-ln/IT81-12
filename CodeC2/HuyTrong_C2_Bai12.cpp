//
#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *previous,*next;
};
Node *first, *last;
void init()
{
	first=NULL;
	last=NULL;
}
void xuat()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout << p->info << endl;
		p=p->next;
	}
}
void ThemDau(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=first;
	p->previous=NULL;
	if (first!=NULL)
		first->previous=p;
	else
		last=p;
	first=p;
}
void ThemCuoi(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if (last!=NULL)
		last->next=p;
	else
		last=p;
}
int XoaDau()
{
	if (first!=NULL)
	{
		Node *p=first;
		first = first->next;
		delete p;
		if (first!=NULL)
			first->previous=NULL;
		else
			last=NULL;
		return 1;
	}
	return 0;
}
int XoaCuoi()
{
	if (last!=NULL)
	{
		Node *p=last;
		(p->previous)->next=NULL;
		return 1;
	}
	return 0;
}
int search(int x)
{
	Node *p;
	p=first;
	while(p!=NULL && p->info!=x)
	{
		p=p->next;
	}
	if(p->info==x)
		return 1;
	return 0;
}
int TimXoa(int x)
{
	Node *p;
	p=first;
	while(p!=NULL && p->info!=x)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		if(p==first)
		{
			if(XoaDau()==1)
				return 1;
			else
				return 0;
		}
		else 
			if(XoaCuoi()==1)
				return 1;
			else
				return 0;
	}
	else
	{
		Node *q;
		q=p->previous;
		q->next=p->next;
		(p->next)->previous=q;
		delete p;
		return 1;
	}
}
int main()
{
	int chon,x,y,z;
	do{
	cout << "1. Khai bao danh sach rong.\n";
	cout << "2. Xuat cac phan tu trong danh sach.\n";
	cout << "3. Them phan tu vao dau danh sach.\n";
	cout << "4. Them phan tu vao cuoi danh sach.\n";
	cout << "5. Xoa phan tu dau danh sach.\n";
	cout << "6. Xoa phan tu cuoi danh sach.\n";
	cout << "7. Tim phan tu de xoa trong danh sach.\n";
	cout << "8. Tim mot phan tu co gia tri bang voi gia tri x hoac gan nhat va lon hon phan tu x nhap vao;Them mot phan tu truoc phan tu tim thay\n";
	cout << "9. Thoat.\n";
	cout << "Ban chon:";
	cin >> chon;
	if(chon<1 || chon>8)
		cout << "Nhap khong hop ly.Nhap lai.\n";
	switch(chon)
	{
	case 1:
		system("cls");
		init();
		cout << "Da khai bao danh sach rong thanh cong!\n";
		break;
	case 2:
		system("cls");
		cout << "Cac phan tu trong danh sach:\n";
		xuat();
		cout << endl;
		break;
	case 3:
		system("cls");
		cout << "Nhap phan tu can them: ";
		cin >> x;
		ThemDau(x);
		cout << "Ban da them thanh cong!\n";
		break;
	case 4:
		system("cls");
		cout << "Nhap phan tu can them: ";
		cin >> y;
		ThemCuoi(y);
		cout << "Ban da them thanh cong!\n";
		break;
	case 5:
		system("cls");
		if(XoaDau()==1)
			cout << "Xoa thanh cong!\n";
		else
			cout << "Xoa khong thanh cong!\n";
		break;
	case 6:
		system("cls");
		if(XoaCuoi()==1)
			cout << "Xoa thanh cong\n";
		else
			cout << "Xoa khong thanh cong\n";
		break;
	case 7:
		system("cls");
		cout << "Nhap phan tu can tim de xoa: ";
		cin >> z;
		if(TimXoa(z)==1)
			cout << "Xoa thanh cong\n";
		else 
			cout << "Xoa khong thanh cong\n";
		break;
	case 8:
		break;
	case 9:
		system("cls");
		break;
	}
	}while(chon !=8 || chon<1 || chon>8);
	system("pause");
	return 0;
}