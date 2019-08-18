//#include <iostream>
//#include <stdio.h>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//#define max 20
//int a[max][max];
//char ten[max];
//int n;
//void init()
//{
//	n = 0;
//}
//void inputfromFile()
//{
//	ifstream inFile;
//	inFile.open("Text.txt");
//	if (inFile.is_open())
//	{
//		inFile >> n;
//		for (int i = 0; i < n; i++)
//			inFile >> ten[i];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				inFile >> a[i][j];
//		cout << "Doc File thanh cong.\n";
//
//	}
//	else
//		cout << "Doc File that bai.\n";
//}
//void output()
//{
//	cout << setw(1) << " ";
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << ten[i];
//	cout << endl;
//	cout << setw(4) << " ";
//	for (int i = 0; i <= n + n - 2; i++)
//		cout << setw(1) << "--";
//	cout << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << ten[i];
//		for (int j = 0; j < n; j++)
//			cout << setw(4) << a[i][j];
//		cout << endl;
//	}
//}
////Stack Queue
//struct node
//{
//	int info;
//	node *link;
//};
//node *front, *rear;
//node *sp;
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
//		front = p->link;
//		x = p->info;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void xuat()
//{
//	if (front != NULL)
//	{
//		node *p = new node;
//		p = front;
//		do
//		{
//			cout << p->info << endl;
//			p = p->link;
//		} while (p != NULL);
//	}
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
////duyet theo chieu rong BFS
//int c[100], bfs[100], nbfs = 0;
//void initC()
//{
//	for (int i = 0; i < n; i++)
//		c[i] = 1;
//}
//
//void BFS(int v)
//{
//	int p;
//	pushQ(v);
//	c[v] = 0;
//	while (front != NULL)
//	{
//		popQ(p);
//		bfs[nbfs] = p;
//		nbfs++;
//		for (int w = 0; w < n; w++)
//			if (c[w] && a[p][w] == 1)
//			{
//				pushQ(w);
//				c[w] = 0;
//			}
//	}
//}
////duyet thao chieu sau DFS
//int dfs[100], ndfs = 0;
//void DFS(int s)
//{
//	pushS(s);
//	dfs[ndfs] = s;
//	ndfs++;
//	c[s] = 0;
//	int v = -1, u = s;
//	while (isEmptyS() == 0)
//	{
//		if (v == n)
//			popS(u);
//		for (v = 0; v < n; v++)
//			if (a[u][v] != 0 && c[v] == 1)
//			{
//				pushS(u);
//				pushS(v);
//				dfs[ndfs] = v;
//				ndfs++;
//				c[v] = 0;
//				u = v;
//				break;
//			}
//	}
//}
////xuat duyet
//void outputD(int a[], int n)
//{
//
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << ten[a[i]];
//}
////tim x bang BFS
//void Seach(int x, int v)
//{
//	int w, p;
//	pushQ(v);
//	c[v];
//	while (front != NULL)
//	{
//		popQ(p);
//		if (x == p)
//		{
//			cout << "\nTim thay x = " << x << "\n";
//			return;
//		}
//		for (w = 0; w < n; w++)
//			if (c[w] && a[p][w] == 1)
//			{
//				pushQ(w);
//				c[w] = 0;
//			}
//	}
//}
////void BFSdequy(int x)
////{
////
////}
//int main()
//{
//	int chon, x;
//	char tt;
//	do {
//		system("cls");
//		cout << "1. Khoi tao ma tran ke\n"
//			<< "2. Nhap ma tran tu file\n"
//			<< "3. Xuat ma tran\n"
//			<< "4. Xuat ma tran ke\n"
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
//			inputfromFile();
//			break;
//		case 3:
//			cout << "Ma tran vua nhap: \n";
//			output();
//			break;
//		case 4:
//			cout << "Ma tran ke \n";
//			output();
//			break;
//		case 5:
//			initQ();
//			initC();
//			cout << "\nNhap vao dinh xuat phat: ";
//			cin >> x;
//			nbfs = 0;
//			BFS(x);
//			cout << "\nThu tu dinh sau khi duyet BFS: " << endl;
//			outputD(bfs, n);
//			break;
//		case 6:
//			initS();
//			initC();
//			cout << "Nhap dinh xuat phat: ";
//			cin >> x;
//			ndfs = 0;
//			DFS(x);
//			cout << "Thu tu dinh sau khi duyet theo DFS: ";
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