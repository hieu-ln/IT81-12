#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

//dslk su dung cho stack va queue
struct node
{
	int info;
	node* link;
};
node* sp;
node* front, * rear;
// stack
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void pushS(int x)
{
	node* p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int& x)
{
	if (sp != NULL)
	{
		node* p= sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//queue
void initQueue() 
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node* p = new node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int& x)
{
	if (front != NULL)
	{
		node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void initGraph()
{
	n = 0;
}
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu nhat " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
// xuat ma tran 
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "\t";
	cout << endl;
}
//cau 4.3
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}
//cau 4.4
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			popS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				pushS(u);
				pushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
//cau 4.5
void search_by_bfs(int x, int v)
{
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (w =0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice, i, x;
	system("cls");
	cout << "--------MENU--------\n";
	cout << "1. Khoi tao ma tran rong\n";
	cout << "2. Nhap ma tran ke\n";
	cout << "3. Xuat ma tran ke\n";
	cout << "4. Duyet do thi theo chieu rong BFS\n";
	cout << "5. Duyet do thi thao chieu sau DFS\n";
	cout << "6. Tim dinh co gia tri x theo BFS\n";
	cout << "7. Thoat\n";
	do {
		cout << "Vui long chon de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao ma tran rong thanh cong\n";
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			initQueue();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu sau khi duyet BFS: \n";
			output(bfs, n);
			break;
		case 5:
			initStack();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu sau khi duyet BFS: \n";
			output(dfs, n);
			break;
		case 6:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			search_by_bfs(x, 0);
			break;
		case 7:
			cout << "GOODBYE........!!!\n";
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}