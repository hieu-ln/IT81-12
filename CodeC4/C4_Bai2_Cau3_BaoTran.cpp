// Bai 2, Chuong 4, Cay nhi phan tim kiem
#include<iostream>
#include<stdlib.h>
using namespace std;

#define COUNT 10
//Cau 2.1 Khai bao cau truc cay NPTK
struct Node
{
	int info;
	Node* left;
	Node* right;
};
Node* root;
Node* sp;
Node* front, * rear;
void InitS()
{
	sp = NULL;
}

void pushS(int x)
{
	Node* p = new Node;
	p->info = x;
}
void InitQ()
{
	front = NULL;
		rear = NULL;
}
// 2.2 khoi tao cay rong
void tree_Empty()
{
	root = NULL;
}

// 2.3 them 1 phan tu vao cay - khong dung de quy
void insertNode(Node*& p, int x)
{

		if (p == NULL)
		{
			p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
		}
		if (p->info < x)
		{
			p = p->right;
		}
		else
			p = p->left;
}
// xuat cay NPTK
void Print2DUtil(Node* p, int space)
{
	//base case
	if (p == NULL)
		return;
	//increase distance between levels
	space += COUNT;
	//process right child first
	Print2DUtil(p->right, space);
	//print current node after space 
	//count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << "\t";
	cout << p->info;
	//process left child
	Print2DUtil(p->left, space);
}

void Process_tree()
{
	Print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "------BAI TAP 2, CHUONG 4, CAY NHI PHAN TIM KIEM -------" << endl;
	cout << "1.Khoi tao cay NPTK rong" << endl;
	cout << "2.Them phan tu vao cay NPTK" << endl;
	cout << "3.Xuat cay NPTK" << endl;
	cout << "4.Thoat" << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			tree_Empty();
			cout << "Ban vua khoi tao cay thanh cong" << endl;
			break;
		case 2:
			cout << "Vui long nhap gia tri x can them: ";
			cin >> x;
			insertNode(root, x);
			cout << "Cay NPTK sau khi them la: " << endl;
			Process_tree();
			break;
		case 3:
			cout << "Cay NPTK nhu sau: " << endl;
			Process_tree();
			break;
		case 4:
			cout << "Goodbye.......!!!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 4);
	system("pause");
	return 0;
}