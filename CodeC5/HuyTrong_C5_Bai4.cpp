//
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX]; 
int n;			 
char vertex[MAX];

struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

void InitStack()
{
	sp = NULL;
}

int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void InitQueue()
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

void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int PopQ(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void InitGraph()
{
	n = 0;
}

void input_graph_from_text()
{
	string line;
	ifstream myfile("BT4.txt");

	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}

void input_graph()
{
	cout << "\nNhap vao so dinh cua do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao so dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

void output_graph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "\t";
}

int C[100], bfs[100];
int nbfs = 0;

void InitC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int v) 
{
	int p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (int w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (a[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

void search_by_bfs(int x, int v)
{
	int w, p;
	PushQ(v);
	C[v];
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "\nTim thay x = " << x << "\n";
			return;
		}
		for (w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	system("cls");

	cout << "Menu:\n"
		 << "1. Khoi tao MA TRAN KE rong.\n"
		 << "2. Nhap MA TRAN KE tu file text.\n"
		 << "3. Nhap MA TRAN KE.\n"
		 << "4. Xuat MA TRAN KE.\n"
		 << "5. Duyet do thi theo chieu rong BFS - DSLK.\n"
		 << "6. Duyet do thi theo chieu sau DFS - DSLK.\n"
		 << "7. Tim dinh co gia tri x theo BFS.\n"
		 << "8. Thoat." << endl;
	do
	{
		cout << "\nBan chon: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "\nBan  vua khoi tao MA TRAN KE rong thanh cong.\n";
			break;
		case 2:
			input_graph_from_text();
			cout << "\nBan vua nhap MA TRAN KE tu file: \n";
			output_graph();
			break;
		case 3:
			input_graph();
			break;
		case 4:
			output_graph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "\nNhap vao dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "\nThu tu dinh sau khi duyet BFS: " << endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "\nNhap vao dinh ban muon bat dau duyet: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "\nThu tu dinh sau khi duyet DFS: ";
			output(dfs, n);
			break;
		case 7:
			cout << "\nVui long nhap vao gia tri x can tim: ";
			cin >> x;
			search_by_bfs(x, 0);
			break;
		case 8:
			break;
		default:
			break;
		}
	} while (choice != 8);
	return 0;
}