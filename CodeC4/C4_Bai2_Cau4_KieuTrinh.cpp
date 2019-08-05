#include<iostream>
using namespace std;
#define COUNT 100
//Khai báo
struct Node
{
	int info;
	Node *left;
	Node *right;
};

Node *createNode(int x)
{
	Node *p=new Node();
	p->info=x;
	p->left=p->right=NULL;
	return p;
}
Node *root;
void init()
{
	root=NULL;
}

//2.4 Tìm một phần tử trong cây (không dùng đệ quy)
Node *find(Node *root, int x)
{
	if (root==NULL)
	{
		return NULL;
	}
	Node *p= root;
	while( p!=NULL)
	{
		if(p-> info >x)
		{
			p=p->left;
		}
		else
		{
			p=p->right;
		}
	}
	return p;
}
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
void Process_print()
{
	print( root, 0);
}
int main()
{
	int x;
	int choice =0;
	system("cls");
	cout<<"---------BAI TAP CHUONG 4-CAY NHI PHAN TIM KIEM-------"<<endl;
	cout<<"1.Khoi tao cay thanh cong\n";
	cout<<"2. Tim mot phan tu trong cay\n";
	cout<<"3. Xuat cay NPTK\n";
	cout<<"4. Thoat\n";
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Ban vua khoi tao cay NPTK thanh cong!\n";
			break;
		case 2:
				cout<<"Nhap gia tri can tim: ";
			cin>>x;
			if(find(root,x)==NULL)
				cout<<x<<"Khong co trong cay!\n";
			else
			{
				cout<<"x co trong cay nhi phan\n";
			}
			break;
		case 3:
			cout<<"Cay NPTK nhu sau: ";
			Process_print();
			break;
		case 4:
			cout<<"Goodbye!\n";
			break;
		default:
			break;
		}
	}while(choice!=5);
	system("Pause");
	return 0;
}