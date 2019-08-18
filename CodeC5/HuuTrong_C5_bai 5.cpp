//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <sstream>
//using namespace std;
//#define max 20
////Stack Queue
//struct node
//{
//	int info;
//	node *link;
//};
//node *first[max];
//int n;
//char tend[max];
//node *front, *rear, *sp;
////Queue
//void initQ()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isEmptyQ()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void pushQ(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (rear != NULL)
//		rear->link = p;
//	else
//		front = p;
//	rear = p;
//}
//int popQ(int &x)
//{
//	if (front != NULL)
//	{
//		node *p = front;
//		x = p->info;
//		front = front->link;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////Stack
//void initS()
//{
//	sp = NULL;
//}
//int isEmptyS()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void pushS(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//int popS(int &x)
//{
//	if (sp != NULL)
//	{
//		node *p = sp;
//		x = p->info;
//		sp = sp->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////danh sach ke
//void init()
//{
//	n = 0;
//}
//void themcuoi(node *&first, node *p)
//{
//	if (first == NULL)
//		first = p;
//	else
//	{
//		node *q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
//void inputtext()
//{
//	string line;
//	ifstream myfile("matranke1.txt");
//	if (myfile.is_open())
//	{
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile >> tend[i];
//		string str;
//		int i = 0;
//		while (getline(myfile, str))
//		{
//			istringstream ss(str);
//			int u;
//			while (ss >> u)
//			{
//				node *p = new node;
//				p->info = u;
//				p->link = NULL;
//				themcuoi(first[i - 1], p);
//			}
//			i++;
//		}
//		cout << i;
//	}
//}
//void input()
//{
//	cout << "Nhap so dinh cua do thi: ";
//	cin >> n;
//	cout << "Nhap ten dinh: ";
//	for (int i = 0; i < n; i++)
//		cin >> tend[i];
//	for (int i = 0; i < n; i++)
//	{
//		int u;
//		string str;
//		while (getline(cin, str))
//		{
//			istringstream ss(str);
//			while (ss >> u)
//			{
//				node *p = new node;
//				p->info = u;
//				p->link = NULL;
//				themcuoi(first[i - 1], p);
//			}
//			break;
//		}
//	}
//}
//void output()
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Dinh " << i << " (" << tend[i] << "): ";
//		node *p = first[i];
//		while (p != NULL)
//		{
//			cout << setw(4) << p->info;
//			p = p->link;
//		}
//		cout << endl;
//	}
//}
////xuat duyet
//void outputD(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << tend[a[i]];
//}
////duyet theo chieu rong BFS
//int c[100], bfs[100], nbfs = 0;
//void initC()
//{
//	for (int i = 0; i < n; i++)
//		c[1];
//}
//void BFS(int v)
//{
//	int p;
//	node *w;
//	pushQ(v);
//	c[v] = 0;
//	while (front != NULL)
//	{
//		popQ(p);
//		bfs[nbfs] = p;
//		w = first[p];
//		nbfs++;
//		while (w != NULL)
//		{
//			if (c[w->info])
//			{
//				pushQ(w->info);
//				c[w->info] = 0;
//			}
//			w = w->link;
//		}
//	}
//}
////duyet thao chieu sau DFS
//int dfs[100], ndfs = 0;
//void DFS(int x)
//{
//	pushS(x);
//	dfs[ndfs] = x;
//	ndfs++;
//	c[x] = 0;
//	int u = x;
//	node *v = NULL;
//	while (!isEmptyS())
//	{
//		if (v == NULL)
//			popS(u);
//		v = first[u];
//		while (v != NULL)
//		{
//			if (c[v->info] == 1)
//			{
//				pushS(u);
//				pushS(v->info);
//				dfs[ndfs] = v->info;
//				ndfs++;
//				c[v->info] = 0;
//				u = v->info;
//				break;
//			}
//			v = v->link;
//		}
//	}
//}
//void Seach(int x, int v)
//{
//	int p;
//	node *w;
//	pushQ(v);
//	c[v] = 0;
//	while (front != NULL)
//	{
//		popQ(p);
//		if (x == p)
//		{
//			cout << "Tim thay x=" << x << endl;
//			return;
//		}
//		w = first[p];
//		while (w != NULL)
//		{
//			if (c[w->info])
//			{
//				pushQ(w->info);
//				c[w->info] = 0;
//			}
//			w = w->link;
//		}
//	}
//}
//int main()
//{
//	int chon, x;
//	char tt;
//	do {
//		system("cls");
//		cout << "1. Khoi tao danh sach ke\n"
//			<< "2. Nhap danh sach tu file\n"
//			<< "3. Nhap danh sach ke\n"
//			<< "4. Xuat danh sach ke\n"
//			<< "5. Duyet do thi theo chieu rong BFS\n"
//			<< "6. Duyet do thi theo chieu sau DFS\n"
//			<< "7. Tim dinh X tren do thi\n";
//		cout << "Chon de thuc hien: ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			init();
//			cout << "Da khoi tao thanh cong ma tran rong!!";
//			break;
//		case 2:
//			inputtext();
//			cout << "Ma tran tu File da duoc nhap thanh cong\n";
//			output();
//			break;
//		case 3:
//			input();
//			break;
//		case 4:
//			cout << "Ma tran ke \n";
//			output();
//			break;
//		case 5:
//			initQ();
//			initC();
//			cout << "Nhap dinh xuat phat: ";
//			cin >> x;
//			BFS(x);
//			cout << "Thu tu dinh sau khi duyet theo BFS: ";
//			outputD(bfs, n);
//			break;
//		case 6:
//			initS();
//			initC();
//			cout << "Nhap dinh xuat phat: ";
//			cin >> x;
//			DFS(x);
//			cout << "Thu tu dinh sau khi duyet theo BFS: ";
//			outputD(dfs, n);
//			break;
//		case 7:
//			cout << "Nhap gia tri x can tim: ";
//			cin >> x;
//			Seach(x, 0);
//			break;
//		}
//		cout << endl;
//		cout << "Ban co muon tiep tuc chuong trinh (Y/N): ";
//		cin >> tt;
//	} while (tt == 'y' || tt == 'Y');
//}