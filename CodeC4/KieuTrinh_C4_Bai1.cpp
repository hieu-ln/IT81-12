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
void init()
{
	root=NULL;
}


// Them mot phan tu vao cay
void insert_Node(Node *&p, int x)
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
		{
			if(p->info>x)
				insert_Node(p->left,x);
			else
				insert_Node(p->right, x);
		}
}

//Them Node khong dung con tro
int insert_Node1(Node*p, int x)
{
	if(p->info==x)
		return 0;
	else
		if(p->info>x)
		{
			if(p->left==NULL)
			{
				Node *y=new Node;
				y->info=x;
				y->left=NULL;
				y->right=NULL;
				p->left=y;
				return 1;
			}
			else
				return insert_Node1(p->left,x);
		}
		else
		{
			if(p->right==NULL)
			{
				Node *y=new Node;
				y->info=x;
				y->left=NULL;
				y->right=NULL;
				p->right =y;
				return 1;
			}
			else
				return insert_Node1(p->right, x);
		}
}
//Xuat cay nhi phan
void print(Node *p, int space)
{
	if(p==NULL)
		return;
	space +=COUNT;
	print (p->right, space);
	cout<<endl;
	for(int i=COUNT; i<space; i++)
		cout<<" ";
	cout<<p->info<<endl;
	print (p->left, space);
}
//Ham xu li xuat
void Process_print()
{
	print( root, 0);
}
//Tim mot phan tu trong cay
void*search(Node *p, int x)
{
	if(p!=NULL)
	{
		if(p->info==x)
			return p;
		else
			if(x>p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
void searchStandFor(Node *&p, Node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else
		searchStandFor(p, q->left);
}
//Xoa mot Node trong cay
int Delete(Node *&T, int x)
{
	if(T==NULL)
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
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right, x);
	if(T->info>x)
		return Delete(T->left, x);
}
//Duyet cay theo thu tu NLR
void duyetNLR(Node *&p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//Duyet cay theo thu tu LNR
void duyetLNR(Node *&p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout<<p->info<<" ";
		duyetLNR(p->right);
	}
}
//Duyet cay theo thu tu LRN
void duyetLRN(Node *&p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout<<p->info<<" ";
	}
}
//Dem so Node
int countNode(Node *p)
{
	if(p==NULL)
		return 0;
	else
		return 1+countNode(p->left)+countNode(p->right);
}
//Tim Node lon nhat
int timMax(Node *p)
{
	if(p==NULL)
		return INT_MIN;
	else
	{
		while (p->right!=NULL)
			p=p->right;
	return p->info;
	}
}
//Dem so Node cay ben trai
int countNodeLeftTree(Node *p)
{
	if(p==NULL||p->left==NULL)
		return 0;
	else
		return countNode(p->left);
}
int main()
{
	int x, t;
	Node *p;
	int choice=0;
	system("cls");
	cout<<"---------BAI TAP CHUONG 4-CAY NHI PHAN TIM KIEM-------"<<endl;
	cout<<"1.Khoi tao cay thanh cong\n";
	cout<<"2.Them mot phan tu vao cay\n";
	cout<<"3. Tim mot phan tu trong cay\n";
	cout<<"4. Xoa mot Node trong cay \n";
	cout<<"5.Duyet cay theo thu tu NLR\n";
	cout<<"6. Duyet cay theo thu tu LNR\n";
	cout<<"7. Duyet cay theo thu tu LRN\n";
	cout<<"8. Tong so Node trong cay la\n";
	cout<<"9.Tim Node lon nhat trong cay\n";
	cout<<"10.Dem so Node cay ben trai\n";
	cout<<"11.Xuat cay NPTK\n";
	cout<<"12.Thoat\n";
	do{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Ban vua khoi tao cay NPTK thanh cong!\n";
			break;
		case 2:
			cout<<"Nhap gia tri them: ";
			cin>>x;
			insert_Node(root, x);
			cout<<"Gia tri cay nhi phan sau khi them  :\n";
			Process_print();
			break;
		case 3:
			cout<<"Nhap gia tri can tim: ";
			cin>>x;
			if(search(root,x)==NULL)
				cout<<x<<"Khong co trong cay!\n";
			else
			{
				cout<<"x co trong cay nhi phan\n";
			}
			break;
		case 4:
			cout<<"Nhap gia tri can xoa: ";
			cin>>x;
			if(Delete(root, x))
			{
				cout<<"Cay sau khi xoa la: \n";
				Process_print();
				cout<<endl;
			}
			else
				cout<<"Xoa khong thanh cong\n";
			break;
		case 5:
			cout<<"Cay duyet theo NLR: \n";
			duyetNLR(root);
			cout<<endl;
			break;
		case 6:
			cout<<"Cay duyet theo LNR: \n";
			duyetLNR(root);
			cout<<endl;
			break;
		case 7:
			cout<<"Cay duyet theo LRN: \n";
			duyetLRN(root);
			cout<<endl;
			break;
		case 8:
			cout<<"Cay nhi phan co "<<countNode(root)<<"node\n";
		case 9:
			if(timMax(root)==INT_MIN)
				cout<<"Cay rong, nen khong co gia tri lon nhat\n";
			else
				cout<<"Gia tri lon nhat trong cay la: "<<timMax(root)<<endl;
			break;
		case 10:
			cout<<countNodeLeftTree(root)<<endl;
		case 11:
			cout<<"Cay NPTK nhu sau: ";
			Process_print();
			break;
		case 12:
			cout<<"Goodbye!\n";
			break;
		default:
			break;
		}
	}while(choice!=13);
	system("Pause");
	return 0;
}

