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
//int timTT(int a[], int n, int x)
//{
//	int i = 0;
//	while (i < n&&a[i] != x)
//		i++;
//	if (i < n)
//		return i;
//	return -1;
//}
//int timNP(int a[], int n, int x)
//{
//	int left = 0, right = n - 1, mid;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (a[mid] == x)
//			return mid;
//		else
//		{
//			if (a[0<a[1]])
//				if (x > a[mid])
//					left = mid + 1;
//				else
//					right = mid - 1;
//			else
//				if (x < a[mid])
//					left = mid + 1;
//				else
//					right = mid - 1;
//		}
//	}
//	return 0;
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
//	char tt;
//	int chon, x, p;
//	system("cls");
//	cout<<"1. Nhap danh sach\n2. Xuat cac phan tu danh sach\n3.Tim phan tu trong danh sach (pp tuan tu)\n4. Tim phan tu trong danh sach (pp nhi phan)\n5. Tim va xoa\n";
//	do{
//		cout<<"Chon de thuc hien: ";
//		cin>>chon;
//		switch (chon)
//		{
//		case 1:
//			cout << "Nhap so phan tu: ";
//			cin >> n;
//			nhap(a,n);
//			break;
//		case 2:
//			cout << "\nMang vua nhap: ";
//			xuat(a, n);
//			break;
//		case 3:
//			cout << "Nhap phan tu can tim: ";
//			cin >> x;
//			if (timTT(a,n,x))
//				cout<<x<<" co trong danh sach, o vi tri "<<timTT(a,n,x)<<endl;
//			else
//				cout<<"Khong tim thay "<<x<<" trong danh sach\n";
//			break;
//		case 4:
//			cout << "Nhap phan tu can tim: ";
//			cin >> p;
//			if (timTT(a, n, x))
//				cout << p << " co trong danh sach, o vi tri " << timNP(a, n, p) << endl;
//			else
//				cout << "Khong tim thay " << p << " trong danh sach\n";
//			break;
//		case 5:
//			int t;
//			cout << "Nhap phan tu muon tim va xoa: ";
//			cin >> t;
//			if (timxoa(a, n, t))
//			{
//				cout << "Tim va xoa thanh cong.\n";
//				cout << "Danh sach sau khi xoa: ";
//				xuat(a, n);
//			}
//			else
//				cout<<"Khong tim thay "<<t<<" trong danh sach, nen thu tuc xoa that bai.\n";
//			break;
//		}
//		cout<<"\nBan co muon tiep tuc (chon Y/N):\n ";
//		cin>>tt;
//	}while(tt=='y'||tt=='Y');
//}