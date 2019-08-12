#include <iostream>
#include <sstream>
using namespace std;
#define MAX 20
#define MAXS 100
int a[100];
int sp;
int A[MAXS][MAXS];
//khoi tao rong stack
void initS(int a[], int& sp)
{
	sp = -1;
}
//ham kiem tra rong
int isEmptyS(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//ham push
int pushS(int a[], int& sp, int x)
{
	if (sp < MAXS - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//ham pop
int popS(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//end stack

//queue
int f;
int r;
//khoi tao queue rong
void initQ(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
// kiem tra queue rong
int isEmptyQ(int a[], int& front, int& rear)
{
	if (front == rear)
		return 1;
	return 0;
}
//them
int pushQ(int a[], int& front, int& rear, int x)
{
	if (rear - front == MAXS - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAXS - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAXS - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}
//lay
int popQ(int a[], int& front, int& rear, int& x)
{
	if (front == 1)
		return 0;
	else
	{
		x = a[front++];
		if (front < rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}
//end

//khai bao
struct Node
{
	int info;
	Node* link;
};
Node* first[MAX];
int n;
char vertex[MAX];
//Khoi tao do thi rong
void initGraph(int n)
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;
	n = 0;
}
void InsertLast(Node*& f, Node* p)
{
	if (f == NULL)
		f = p;
	else
	{
		Node* q = f;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
//7.1 Nhap ma tran
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n + 1; i++)
	{
		if (i > 0)
			cout << "Nhap danh sach cua dinh thu" << i - 1 << "( " << vertex[i - 1] << ") : ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				//dinh u
				Node* p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(first[i - 1], p);
			}
			break;
		}
	}
}
//7.2 Xuat do thi
void output(int b[], int nb)
{
	for (int i = 0; i < n; i++)
		cout << vertex[b[i]] << "  ";
}
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " ( " << vertex[i] << ") : ";
		Node* p = first[i];
		while (p != NULL)
		{
			cout << p->info << "  ";
			p = p->link;
		}
		cout << endl;
	}
}
//7.3
//5.3 BFS: duyet theo chieu rong
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)//v la dinh bat dau
{
	int p;
	Node* w;
	pushQ(a, f, r, v);
	C[v] = 0;
	while (f != NULL)
	{
		popQ(a, f, r, p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while (w != NULL)
		{
			if (C[w->info])
			{
				pushQ(a, f, r, w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}
//5.4 Duyet do thi theo chieu sau
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(a, sp, s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node* v = NULL;
	while (isEmptyS(a, sp) == 0)
	{
		if (v == NULL)
			popS(a, sp, u);
		v = first[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				pushS(a, sp, u);
				pushS(a, sp, v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}

	}
}
//cau 7.5
void Search_by_DFS(int x, int s)//s la dinh bat dau
{

	pushS(a, sp, s);
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmptyS(a, sp))
	{
		if (v == n)
		{
			popS(a, sp, u);
			if (u == x)
			{
				cout << x << " ton tai!";
				return;
			}
		}
		for (v = 0; v < n; v++)
		{
			if (A[u][v] != 0 && C[v] == 1)
			{
				pushS(a, sp, u);
				pushS(a, sp, v);
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}

int main()
{
	int choice, x;
	cout << "---BAI 6, CAU 5, CHUONG 5, DUYET DFS---" << endl;
	cout << "1.Khoi tao ma tran rong" << endl
		<< "2.Nhap ma tran ke cua do thi 5.1" << endl
		<< "3.Xuat ma tran ke" << endl
		<< "4.Tim dinh X trong do thi" << endl
		<< "5.Thoat" << endl;

	do {
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			initGraph(n);
			cout << "Khoi tao ma tran rong thanh cong!";
			break;
		case 2:
			inputGraph();
			cout << "Ma tran ke" << endl;
			outputGraph();
			break;
		case 3:
			cout << "Ma tran ke" << endl;
			outputGraph();
			break;
		case 4:
			cout << "Chon dinh can tim: ";
			cin >> x;
			initC();
			initS(a, sp);
			Search_by_DFS(x, 0);
			break;
		case 5:
			cout << "Goodbye!";
			break;
		default:
			cout << "Loi nhap lieu!";
			break;
		}
	} while (choice != 5);

	cout << endl;
	system("pause");
	return 0;
}
