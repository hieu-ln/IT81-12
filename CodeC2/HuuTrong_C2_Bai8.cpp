//#include <iostream>
//using namespace std;
//#define max 100
//int a[max];
//int sp;
//void khoitao(int a[],int &sp)
//{
//	sp=-1;
//}
//int ktrong(int a[],int sp)
//{
//	if (sp==-1)
//		return 1;
//	return 0;
//}
//int ktday(int a[],int sp)
//{
//	if (sp==max-1)
//		return 1;
//	return 0;
//}
//int them(int a[],int &sp,int x)
//{
//	if (sp<max-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
//int xoa(int a[],int &sp,int &x)
//{
//	if (sp!=-1)
//	{
//		x=a[sp--];
//		return 1;
//	}
//	return 0;
//}
//int Dec_Bin(int so)
//{
//	khoitao(a, sp);
//	int bin = 0;
//	while (so != 0)
//	{
//		int du = so % 2;
//		if (them(a, sp, du))
//			so /= 2;
//		else
//			break;
//	}
//	while (!ktrong(a, sp))
//	{
//		int x;
//		if (xoa(a, sp, x))
//			bin = bin * 10 + x;
//		else
//			break;
//	}
//	return bin;
//}
//int Dec_Oct(int so)
//{
//	khoitao(a, sp);
//	int oct = 0;
//	while (so != 0)
//	{
//		int du = so % 8;
//		if (them(a, sp, du))
//			so /= 8;
//		else
//			break;
//	}
//	while (!ktrong(a, sp))
//	{
//		int x;
//		if (xoa(a, sp, x))
//			oct = oct * 10 + x;
//		else
//			break;
//	}
//	return oct;
//}
//int (int)
//int chuyen(int x)
//{
//	char a;
//	while (x != 0)
//	{
//		int t = x % 16;
//		if
//	}
//}
//int Dec_Hex(int so)
//{
//	char b[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//	khoitao(a, sp);
//	int hex = 0;
//	while (so != 0)
//	{
//		int du = so % 16;
//		if (them(a, sp, du))
//			so /= 16;
//		else
//			break;
//	}
//	while (!ktrong(a, sp))
//	{
//		int x;
//		if (xoa(a, sp, x))
//			hex = hex * 10 + x;
//		else
//			break;
//	}
//
//	return hex;
//}
//int main()
//{
//	char tt;
//	int chon;
//	system("cls");
//	cout << "1. Chuyen tu thap phan sang nhi phan\n2. Chuyen tu thap phan sang bat phan\n3. Chuyen tu thap phan sang thap luc phan\n";
//	do {
//		cout << "Chon de thuc hien: ";
//		cin >> chon;
//		switch (chon)
//		{
//			case 1:
//				int x;
//				cout << "Nhap gia tri muon doi: ";
//				cin >> x;
//				if (Dec_Bin(x))
//					cout << "Dang nhi phan cua " << x << " la: " << Dec_Bin(x) << endl;
//				break;
//			case 2:
//				int p;
//				cout << "Nhap gia tri muon doi: ";
//				cin >> p;
//				if (Dec_Oct(p))
//					cout << "Dang bat phan cua " << p << " la: " << Dec_Oct(p) << endl;
//				break;
//			case 3:
//				int h;
//				cout << "Nhap gia tri muon doi: ";
//				cin >> h;
//				if (Dec_Hex(h))
//					cout << "Dang thap luc phan cua " << h << " la: " << Dec_Hex(h) << endl;
//				break;
//		}
//		cout << "\nBan co muon tiep tuc (chon Y/N):\n ";
//				cin>>tt;
//	}while(tt=='y'||tt=='Y');
//}