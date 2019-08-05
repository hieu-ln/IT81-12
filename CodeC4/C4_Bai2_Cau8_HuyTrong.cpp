//
#include<iostream>
using namespace std;
#define MAX 100
#define COUNT 10
int a[MAX];
int front, rear;
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
void init_queue()
{
	front = NULL;
	rear = NULL;
}

void Push(int x)
{
	queue* p;
	p = new queue;
	p->info = x;
	p->next = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
}

int Pop(int& x)
{
	if (front != NULL)
	{
		queue* p = front;
		x = p->info;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void duyetLRN(Node *p)//Dung queue
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		Push(p->info);
	}
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
	cout << "5.Duyet cay theo thu tu LRN(dung queue).\n";
	cout << "6.Thoat.\n";
	cout << "Ban chon:";
	cin >> chon;
	if(chon<1 || chon>6)
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
		cout << "Duyet cay theo thu tu LRN:";
		duyetLRN(root);
		cout << endl;
		break;
	case 6:
		system("cls");
		break;
	}
	}while(chon>=1 && chon<6);
	system("pause");
	return 0;
}