//#include <iostream>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//#define max 20
//int a[max][max];
//int n;
//char dinh[max]/*={'a','b','c','d','e','g'}*/;
//void init()
//{
//	n = 0;
//}
//void input()
//{
//	cout << "Nhap so dinh cua do thi: ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap ten dinh: ";
//		cin >> dinh[i];
//		cout << "Nhap trong so cua dinh " << dinh[i] << ": ";
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//		cout << endl;
//	}
//}
//void inputfromFile()
//{
//	ifstream inFile;
//	inFile.open("Gmap.txt");
//	if (inFile.is_open())
//	{
//		inFile >> n;
//		for (int i = 0; i < n; i++)
//			inFile >> dinh[i];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				inFile >> a[i][j];
//		cout << "Doc File thanh cong.\n";
//		inFile.close();
//	}
//	else
//		cout << "Doc File that bai.\n";
//}
//void output()
//{
//	cout << setw(1) << " ";
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << dinh[i];
//	cout << endl;
//	cout << setw(4) << " ";
//	for (int i = 0; i <= 4 + n; i++)
//		cout << setw(1) << "--";
//	cout << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << dinh[i];
//		for (int j = 0; j < n; j++)
//			cout << setw(4) << a[i][j];
//		cout << endl;
//	}
//}
//
////Thuat giai Prim//
//
////Khai bao TapE
//int E1[max];
//int E2[max];
//int wE[max];
//int nE = 0;
////Khai bao TapT
//int T1[max];
//int T2[max];
//int wT[max];
//int nT = 0;
////Kiem tra ton tai
//int tontai(int d, int D[], int nD)
//{
//	for (int i = 0; i < nD; i++)
//		if (D[i] == d)
//			return 1;
//	return 0;
//}
////Xoa vi tri
//void xoavitri(int i)
//{
//	for (int j = i; j < nE; j++)
//	{
//		E1[j] = E1[j + 1];
//		E2[j] = E2[j + 1];
//		wE[j] = wE[j + 1];
//	}
//	nE--;
//}//Xoa canh
//void xoacanhE(int u, int v)
//{
//	for (int i = 0; i < nE; i++)
//		if (E1[i] == u && E2[i] == v)
//		{
//			xoavitri(i);
//			break;
//		}
//}
//void prim(int s)
//{
//	int u = s, min, i, d1, d2;
//	while (nT < n - 1)
//	{
//		for (int v = 0; v < n; v++)
//			if (a[u][v] != 0)
//				if (tontai(v, T2, nT) == 0)
//				{
//					E1[nE] = u;
//					E2[nE] = v;
//					wE[nE] = a[u][v];
//					nE++;
//				}
//		for (i = 0; i < nE; i++)
//			if (tontai(E2[i], T2, nT) == 0)
//			{
//				min = wE[i]; d1 = E1[i];
//				d2 = E2[i];
//				break;
//			}
//		for (i = 0; i < nE; i++)
//			if (tontai(E2[i], T2, nT) == 0)
//				if (min > wE[i])
//				{
//					min = wE[i]; d1 = E1[i];
//					d2 = E2[i];
//				}
//		T1[nT] = d1; T2[nT] = d2;
//		wT[nT] = a[d1][d2];
//		a[d1][d2] = 0;
//		a[d2][d1] = 0;
//		nT++;
//		xoacanhE(d1, d2);
//		u = d2;
//	}
//}
//void outprim()
//{
//	int tong = 0;
//	for (int i = 0; i < nT; i++)
//	{
//		cout << endl << "(" << T1[i] << "," << T2[i] << ")=" << wT[i];
//		cout << setw(4) << dinh[T1[i]] << dinh[T2[i]];
//		tong += wT[i];
//	}
//	cout << "\n Tong= " << tong;
//
//}
////Ham main
//int main()
//{
//	int chon, x;
//	char tt;
//	do {
//		system("cls");
//		cout << "1. Khoi tao ma tran trong so.\n"
//			<< "2. Nhap ma tran trong so tu ban phim\n"
//			<< "3. Nhap ma tran trong so tu File.\n"
//			<< "4. Xuat ma tran trong so.\n"
//			<< "5. Thuat giai Prim.\n";
//		cout << "Chon de thuc hien: ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao thanh cong!!!";
//			break;
//		case 2:
//			input();
//			break;
//		case 3:
//			inputfromFile();
//			break;
//		case 4:
//			cout << "Ma tran trong so vua nhap:\n";
//			output();
//			break;
//		case 5:
//			cout << "Nhap vi tri dinh bat dau: ";
//			cin >> x;
//			prim(x);
//			outprim();
//			break;
//		}
//		cout << endl;
//		cout << "Ban co muon tiep tuc chuong trinh (Y/N): ";
//		cin >> tt;
//	} while (tt == 'y' || tt == 'Y');
//}