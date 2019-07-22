//#include <iostream>
//#include <iomanip>
//using namespace std;
//#define max 100
//int a[max];
//int n;
//void nhap(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap a[" << i << "]=";
//		cin >> a[i];
//	}
//}
//void xuat(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << a[i];
//}
//int tim(int a[], int n, int x)
//{
//	int i = 0;
//	while ((i < n) && (a[i] != x))
//		i++;
//	if (i == n)
//		return -1;
//	return i;
//}
//int themcuoi(int a[], int &n, int x)
//{
//	if (n >= 0 && n < max - 1)
//	{
//		a[n] = x;
//		n++;
//		return 1;
//	}
//	return 0;
//}
//int xoacuoi(int a[], int &n)
//{
//	if (n >= 0 && n < max - 1)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int xoa(int a[], int &n,int vti)
//{
//	if (vti >= 0 && vti < n)
//	{
//		for (int i = vti; i < n; i++)
//			a[i] = a[i + 1];
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int timxoa(int a[], int &n, int x)
//{
//	if (tim(a, n, x) == -1)
//		return 0;
//	if (xoa(a, n, tim(a, n, x)))
//		return 1;
//}
//int main()
//{
//	int n, x, vt, p;
//	cout << "\nNhap so phan tu: ";
//	cin >> n;
//	nhap(a, n);
//	cout << "\nMang vua nhap: ";
//	xuat(a, n);
//	cout << "\nNhap gia tri can tim: ";
//	cin >> x;
//	if (tim(a, n, x))
//		cout << "\nGia tri nam o vi tri thu " << tim(a, n, x);		
//	else
//		cout << "\nGia tri khong co trong danh sach.";
//	cout << "\nNhap gia tri can them: ";
//	cin >> p;
//	if (themcuoi(a, n, p))
//	{
//		cout << "\nThem cuoi thanh cong.";
//		cout << "\nMang vua them: ";
//		xuat(a, n);
//	}
//	else
//		cout << "\nXoa khong thanh cong.\n";
//	if (xoacuoi(a, n))
//	{
//		cout << "\nXoa cuoi thanh cong.";
//		cout << "\nMang vua xoa: ";
//		xuat(a, n);
//	}
//	cout << "\nNhap vi tri can xoa: ";
//	cin >> vt;
//	if (xoa(a, n,vt))
//	{
//		cout << "\nXoa thanh cong.";
//		cout << "\nMang vua xoa: ";
//		xuat(a, n);
//	}
//	if (timxoa(a, n, x))
//	{
//		cout << "\nTim va xoa thanh cong.";
//		cout << "\nMang vua xoa: ";
//		xuat(a, n);
//	}
//	else
//		cout << "\nKhong tim thay gia tri de xoa.";
//	cout << endl;
//	system("pause");
//	return 0;
//}