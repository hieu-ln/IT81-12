////Bai 8, Chuong 2, DSLK, QUEUE, STACK
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//// Khai bao cau truc stack
//#define MAX 100
//int a[MAX];
//int n;
//// tao stack rong
//void init(int a[], int& n)
//{
//	n = -1;
//}
//// Xet stack rong
//int isEmty(int a[], int n)
//{
//	if (n == -1)
//		return 1;
//	return 0;
//}
//// Xet stack day
//int isFull(int a[], int n)
//{
//	if (n == MAX - 1)
//		return 1;
//	return 0;
//}
//// Them phan tu vao stack
//int Push(int a[], int& n, int x)
//{
//	if (n < MAX - 1)
//	{
//		a[++n] = x;
//		return 1;
//	}
//	return 0;
//}
//// Lay phan tu stack
//int Pop(int a[], int& n, int &x)
//{
//	if (n != -1)
//	{
//		x = a[n--];
//		return 1;
//	}
//	return 0;
//}
//// Chuyen he 10 sang he 2
//void convertDectoBin(int b)
//{
//	int du;
//	while (b != 0)
//	{
//		du = b % 2;
//		Push(a, n, du);
//		b = b / 2;
//	}
//}
//// In ra he so 2
//void Bin()
//{
//	int x;
//	while (n != -1)
//		Pop(a, n, x);
//	cout << x;
//}
//int main()
//{
//		int choice, x;
//		system("cls");
//		cout << "------------BAI TAP 8, CHUONG 2, DSLK, QUEUE, STACK----------" << endl;
//		cout << "1. Khoi tao stack" << endl;
//		cout << "2. Xet stack rong" << endl;
//		cout << "3. Xet stack day" << endl;
//		cout << "4. Them phan tu vao stack" << endl;
//		cout << "5. Lay phan tu stack" << endl;
//		cout << "6. Chuyen he 10 sang he 2" << endl;
//		cout << "7. Thoat" << endl;
//		do
//		{
//			cout << "Vui long chon so de thuc hien: ";
//			cin >> choice;
//			switch (choice)
//			{
//			case 1:
//				init(a, n);
//				cout << "Ban vua nhap stack thanh cong!\n";
//				break;
//			case 2:
//				int c;
//				c = isEmty(a, n);
//				if (c == 1)
//					cout << "Danh sach rong\n";
//				else
//					cout << "Danh sach khong rong\n";
//				break;
//			case 3:
//				int m;
//				m = isFull(a, n);
//				if (m == 1)
//					cout << "Danh sach day\n";
//				else
//					cout << "Danh sach khong day\n";
//				break;
//			case 4:
//				cout << "Nhap gia tri can them: ";
//				cin >> x;
//				int i;
//				i = Push(a, n, x);
//				if (i == 1)
//					cout << "Them thanh cong\n";
//				else
//					cout << "Them khong thanh cong\n";
//				break;
//			case 5:
//				int p;
//				p = Pop(a, n, x);
//				if (p == 1)
//					cout << "Xoa thanh cong\n";
//				else
//					cout << "Xoa khong thanh cong\n";
//				break;
//			case 6:
//				int d;
//				cout << "Nhap so he 10: ";
//				cin >> d;
//				convertDectoBin(d);
//				cout << "He 2: ";
//				Bin();
//				cout << endl;
//				break;
//			case 7:
//				cout << "Goodbye!"<<endl;
//				break;
//			default:
//				break;
//
//			}
//		} while (choice != 7);
//		system("Pause");
//		return 0;
//
//}