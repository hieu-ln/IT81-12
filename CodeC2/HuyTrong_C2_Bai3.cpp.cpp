#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *first;
void init()
{
	first = NULL;
}
void xuat()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout << p->info << "\t";
		p=p->link;
	}
}
int Tim(int x)
{
	Node *p;
	p=first;
	while(p!=NULL && p->info!=x)
	{
		p=p->link;
	}
	if(p->info==x)
		return 1;
	return 0;
}
void ThemDau(int x)
{
	Node *p;
	p=first;
	if(first=NULL)
	{
		p->info=x;
		p->link=NULL;
	}
	else
	{
		Node *r;
		r=new Node;
		r->info=x;
		r->link=p;
		first=r;
	}
}
int XoaDau()
{
	Node *p;
	p=first;
	if(p!=NULL)
		delete p;
	else
		return 1;
}
int XoaCuoi()
{
	Node *p;
	p=first;
	if(first==NULL)
		return 1;
	else if(p->link=NULL)
	{
		delete p;
		return 0;
	}
	else
	{
		while(p!=NULL && p->link!=NULL)
			p=p->link;
		Node *r;
		r=first;
		while(r!=NULL && r->link!=p)
			r=r->link;
		r->link=NULL;
		delete p;
		return 0;
	}
}
void ThemCuoi(int x)
{
	Node *p;
	p=first;
	if(first==NULL)
	{
		p->info=x;
		p->link=NULL;
	}
	else
	{
		while(p!=NULL && p->link!=NULL)
			p=p->link;
		Node *r;
		r=new Node;
		p->link=r;
		r->info=x;
		r->link=NULL;
	}
}
int TimXoa(int x)
{
	Node *p;
	p=first;
	if(p->info==x)
	{
		delete p;
		return 1;
	}
	while(p!=NULL && p->info!=x)
		p=p->link;
	if(p->info=x)
	{
		if(p->link==NULL)
		{
			Node *r;
			r=first;
			while(r!=NULL && r->link!=p)
				r=r->link;
			r->link=NULL;
			delete p;
			return 1;
		}
		else
		{
			Node *k;
			k=first;
			while(k!=NULL && k->link!=p)
				k=k->link;
			k->link=p->link;
			delete p;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int chon,x,y,z,k;
	do{
	cout << "Nhap yeu cau:\n";
	cout << "1.Khoi tao danh sach rong.\n";
	cout << "2.Xuat cac phan tu trong danh sach.\n";
	cout << "3.Tim mot phan tu trong danh sach.\n";
	cout << "4.Them mot phan tu vao dau danh sach.\n";
	cout << "5.Xoa phan tu dau danh sach.\n";
	cout << "6.Them phan tu vao cuoi danh sach.\n";
	cout << "7.Xoa phan tu cuoi danh sach.\n";
	cout << "8.Xoa phan tu tim thay trong danh sach.\n";
	cout << "9.Chuyen thanh danh sach co thu tu.\n";
	cout << "10.Thoat.\n";
	cout << "Ban chon: ";
	do{
	cin >> chon;
	if(chon<1 || chon>10)
		cout << "Nhap yeu cau khong thich hop.Nhap lai: ";
	}while(chon<1 || chon>10);
		switch(chon)
		{
			case 1:
				system("cls");
				init();
				cout << "Ban da khoi tao danh sach rong thanh cong!\n";
				break;
			case 2:
				system("cls");
				cout << "Cac phan tu trong danh sach: ";
				xuat();
				cout << endl;
				break;
			case 3:
				system("cls");
				cout << "Nhap phan tu muon tim trong danh sach:";
				cin >> x;
				if(Tim(x)==1)
					cout << x << " co trong danh sach.\n";
				else
					cout << x << " khong co trong danh sach. \n";
				break;
			case 4:
				system("cls");
				cout << "Nhap phan tu can them vao dau danh sach:";
				cin >> y;
				ThemDau(y);
				cout << "Them thanh cong!\n";
				break;
			case 5:
				system("cls");
				if(XoaDau()==1)
					cout << "Xoa khong thanh cong\n";
				else
					cout << "Xoa thanh cong\n";
				break;
			case 6:
				system("cls");
				cout << "Nhap phan tu muon them vao cuoi danh sach: ";
				cin >> z;
				ThemCuoi(z);
				cout << "Them thanh cong!\n";
				break;
			case 7:
				system("cls");
				if(XoaCuoi()==1)
					cout << "Xoa khong thanh cong!\n";
				else
					cout << "Xoa thanh cong!\n";
				break;
			case 8:
				system("cls");
				cout << "Nhap phan tu can tim de xoa trong danh sach: ";
				cin >> k;
				if(TimXoa(k)==1)
					cout << "Xoa thanh cong!\n";
				else
					cout << "Xoa khong thanh cong!\n";
				break;
			case 9:
			case 10:
				system("cls");
				break;
		}
	}while(chon>=1 && chon<10);
	system("pause");
	return 0;
}