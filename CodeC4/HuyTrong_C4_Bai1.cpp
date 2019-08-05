#include<iostream>
using namespace std;
#define COUNT 10
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void tree_empty()
{
	root=NULL;
}
void insert_node(Node *&p,int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
		if(p->info==x)
			return;
		else
			if(p->info>x)
				insert_node(p->left,x);
			else
				insert_node(p->right,x);
}
void print(Node *p,int space)
{
	if(p==NULL)
		return;
	space+=COUNT;
	print(p->right,space);
	cout << endl;
	for(int i=COUNT;i<space;i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left,space);
}
void Process_print()
{
	print(root,0);
}
int search(Node *p,int x)
{
	if(p!=NULL)
	{
		if(p->info==x)
			return 1;
		else
			if(x>p->info)
				return search(p->right,x);
			else
				return search(p->left,x);
	}
	return 0;
}
void searchStandFor(Node *&p,Node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else
		searchStandFor(p,q->left);
}
int Delete(Node *&T,int x)
{
	if(T=NULL)
		return 0;
	if(T->info==x)
	{
		Node *p=T;
		if(T->left==NULL)
			T=T->right;
		else
			if(T->right==NULL)
				T=T->left;
			else
				searchStandFor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right,x);
	if(T->info>x)
		return Delete(T->left,x);
}
void duyetNLR(Node *p)
{
	if(p!=NULL)
	{
		cout << p->info << "\t";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLNR(Node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout << p->info << "\t";
		duyetLNR(p->right);
	}
}
void duyetLRN(Node *p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << "\t";
	}
}
int count_node(Node *p)
{
	if(p==NULL)
		return 0;
	else
		return 1+count_node(p->left)+count_node(p->right);
}
int count_nodeleft(Node *p)
{
	if(p==NULL || p->left==NULL)
		return 0;
	else
		return count_node(p->left);
}
int TimMax(Node *p)
{
	if(p==NULL)
		return INT_MIN;
	else
		p=p->right;
	return p->info;
}
int main()
{
	int chon,x,y,z;
	do{
	do{
	cout << "Menu:\n";
	cout << "1.Khoi tao cay rong.\n";
	cout << "2.Them mot phan tu vao cay.\n";
	cout << "3.Tim mot phan tu trong cay.\n";
	cout << "4.Xoa mot not trong cay.\n";
	cout << "5.Duyet cay theo thu tu NLR.\n";
	cout << "6.Duyet cay theo thu tu LNR.\n";
	cout << "7.Duyet cay theo thu tu LRN.\n";
	cout << "8.Dem so node cua cay.\n";
	cout << "9.Dem so node ben trai cua cay.\n";
	cout << "10.Tim node lon nhat cua cay.\n";
	cout << "11.Thoat.\n";
	cout << "Ban chon:";
	cin >> chon;
	if(chon<1 || chon>11)
		cout << "Chon khong phu hop.Chon lai!\n";
	}while(chon<1 || chon>8);
	switch(chon)
	{
	case 1:
		system("cls");
		tree_empty();
		cout << "Khoi tao thanh cong!\n";
		break;
	case 2:
		system("cls");
		cout << "Nhap phan tu muon them:";
		cin >> x;
		insert_node(root,x);
		cout << "Them thanh cong!\n";
		cout << "Cay nhi phan sau khi them:\n";
		Process_print();
		break;
	case 3:
		system("cls");
		cout << "Nhap phan tu muon tim trong cay:";
		cin >> y;
		if(search(root,y)==1)
			cout << "Node can tim co trong cay.\n";
		else
			cout << "Node can tim khong co trong cay.\n";
		break;
	case 4:
		system("cls");
		cout << "Nhap node can xoa:";
		cin >> z;
		if(Delete(root,z)==0)
			cout << "Xoa khong thanh cong.\n";
		else
			cout << "Xoa thanh cong.\n";
		cout << "Cay nhi phan sau khi xoa:\n";
		Process_print();
		break;
	case 5:
		system("cls");
		cout << "Duyet cay theo thu tu NLR:";
		duyetNLR(root);
		cout << endl;
		break;
	case 6:
		system("cls");
		cout << "Duyet cay theo thu tu LNR:";
		duyetLNR(root);
		cout << endl;
		break;
	case 7:
		system("cls");
		cout << "Duyet cay theo thu tu LRN:";
		duyetLRN(root);
		cout << endl;
		break;
	case 8:
		system("cls");
		cout << "So node trong cay: " << count_node(root) << endl;
		break;
	case 9:
		system("cls");
		cout << "So node trai cua cay: " << count_nodeleft(root) << endl;
	case 10:
		system("cls");
		if(TimMax(root)==INT_MIN)
			cout << "Khong the tim node lon nhat trong cay.\n";
		else
			cout << "Node lon nhat trong cay la: " << TimMax(root) << endl;
		break;
	case 11:
		system("cls");
		break;
	}
	}while(chon>=1 && chon<11);
	system("pause");
	return 0;
}