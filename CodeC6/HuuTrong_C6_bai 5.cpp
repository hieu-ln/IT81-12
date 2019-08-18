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
//	inFile.open("Text.txt");
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
//void out()
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
////Giai thuat Kruskal
//void kruskal()
//{
//	for (int i = 0; i < nE; i++)
//	{
//		if (tontai(E1[i], T1, nT) == 1 && tontai(E2[i], T2, nT) == 1)
//			continue;
//		if (tontai(E1[i], T2, nT) == 1 && tontai(E2[i], T1, nT) == 1)
//			continue;
//		T1[nT] = E1[i];
//		T2[nT] = E2[i];
//		wT[nT] = wE[i];
//		nT++;
//		if (nT == n - 1)
//			break;
//	}
//}
//void taoE()
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			if (a[i][j] != 0)
//			{
//				E1[nE] = i;
//				E2[nE] = j;
//				wE[nE] = a[i][j];
//				a[i][j] = 0;
//				a[j][i] = 0;
//				nE++;
//			}
//
//}
//void swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = a;
//}
//void sapxepE()
//{
//	for (int i = 0; i < nE - 1; i++)
//		for (int j = i + 1; j < nE; j++)
//			if (wE[i] > wE[j])
//			{
//				swap(wE[i], wE[j]);
//				swap(E1[i], E1[j]);
//				swap(E2[i], E2[j]);
//			}
//}
//
////Ham main
//int main()
//{
//	int chon, x;
//	char tt;
//	do {
//		system("cls");
//		cout << "1. Khoi tao ma tran trong so.\n"
//			<<" 2. Nhap ma tran trong so tu ban phim\n"
//			<< "3. Nhap ma tran trong so tu File\n"
//			<< "4. Xuat ma tran trong so.\n"
//			<< "5. Thuat giai Kruskal\n";
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
//			sapxepE();
//			taoE();
//			
//			kruskal();
//			out();
//			break;
//
//		}
//		cout << endl;
//		cout << "Ban co muon tiep tuc chuong trinh (Y/N): ";
//		cin >> tt;
//	} while (tt == 'y' || tt == 'Y');
//}