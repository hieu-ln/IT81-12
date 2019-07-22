//
#include <iostream>
using namespace std;
struct DonThuc
{
	float heso;
	int somu;
};
struct Node
{
	DonThuc info;
	Node *pNext;
};
struct DaThuc
{
	Node *pHead;
};
void ListInit(DaThuc &tmp)
{
	tmp.pHead=0;
}
void Add(DaThuc &L,DonThuc t)
{
	Node *tmp = new Node;
	tmp->info=t;
if(L.pHead == NULL || L.pHead->info.somu<t.somu)
{
	tmp->pNext=L.pHead;
	L.pHead=tmp;
}
else
{
	Node *cur=L.pHead;
	while(cur->pNext && cur->pNext->info.somu>=t.somu)
	{
		cur=cur->pNext;
	}
	if(cur->info.somu==t.somu)
		cur->info.heso +=t.heso;
	else
	{
		tmp->pNext = cur->pNext;
		cur->pNext=tmp;
	}
}
}
void nhap(DaThuc &tmp)
{
	DonThuc t;
	do{
		cout << endl << "He so: "; 
		cin >> t.somu;
		Add(tmp,t);
	}
	while(t.somu>0);	
}
void xuat(DaThuc &L)
{
	Node *cur=L.pHead;
	if(cur)
	{
		cout << cur->info.heso << "X^" << cur->info.somu;
		cur=cur->pNext;
	}
	while(cur)
	{
		if(cur->info.heso)
		{
			if(cur->info.heso>0) cout << "+";
			cout << cur->info.heso;
			if(cur->info.somu) cout << "X^" << cur->info.somu;
		}
		cur=cur->pNext;
	}
}
DaThuc Cong2Dathuc(DaThuc a, DaThuc b)
{
	{ 
	DaThuc tmp;
	ListInit(tmp);
	Node *cur = a.pHead;
	while (cur)
	{
	Add(tmp,cur->info);
	cur=cur->pNext;
	} 
	cur = b.pHead;
	while (cur)
	{ 
	Add(tmp,cur->info);
	cur=cur->pNext;
	} 
	return tmp;
	}
}
DaThuc Nhan2Dathuc(DaThuc a, DaThuc b)
{
DaThuc tmp;
ListInit(tmp);
Node *cur_a=a.pHead;
Node *cur_b; DonThuc t;
while (cur_a)
{ cur_b=b.pHead;
while (cur_b)
{ 
t.heso = cur_a->info.heso * cur_b->info.heso;
t.somu = cur_a->info.somu + cur_b->info.somu;
Add(tmp,t); cur_b=cur_b->pNext;
} 
cur_a=cur_a->pNext;
} 
return tmp;
}
int main()
{
	int chon;
	DaThuc tmp;
	DaThuc a,b;
	do{
	do{
	cout << "Menu:\n";
	cout << "1.Nhap da thuc.\n";
	cout << "2.Xuat da thuc.\n";
	cout << "3.Cong da thuc.\n";
	cout << "4.Nhan da thuc.\n";
	cout << "5.Thoat.\n";
	cout << "Ban chon: ";
	cin >> chon;
	if(chon<1 || chon>5)
		cout << "Chon khong phu hop.Chon lai!\n";
	}while(chon<1 || chon>5);
	switch(chon)
	{
	case 1:
		system("cls");
		cout << "Nhap da thuc thu nhat:\n";
		nhap(a);
		cout << "Nhap da thuc thu hai:\n";
		nhap(b);
		break;
	case 2:
		system("cls");
		cout << "Xuat da thuc thu nhat:\n";
		xuat(a);
		cout << "Xuat da thuc thu hai:\n";
		xuat(b);
		break;
	case 3:
		system("cls");
		Cong2Dathuc(a,b);
		break;
	case 4:
		system("cls");
		Nhan2Dathuc(a,b);
		break;
	case 5:
		system("cls");
		break;
	}
}while(chon>=1 && chon<5);
	system("pause");
	return 0;
}