#include <iostream>
#include <iomanip>
using namespace std;
#define max 100
int a[max];
int n;
void khoitaonn(int a[], int &n)
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 20;
}
void nhap(int a[], int &n)
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu a[" << i << "]= ";
		cin >> a[i];
		cout << endl;
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(4) << a[i];
}
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void selectionsort(int a[], int n)
{
	int vt;
	for (int i = 0; i < n; i++)
	{
		vt = i;
		for (int j = i + 1; j < n; j++)
			if (a[vt] == a[j])
				vt = j;
		if (vt != i)
			swap(a[vt], a[i]);
	}
}
void interchange(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; i < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void insertionsort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int j = i - 1;
		while (a[j] > x&&j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void bubblesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j++)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
void quicksort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quicksort(a, left, j);
	if (i < right)
		quicksort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		swap(a[i], a[j]);
		shift(a, j, n);
	}
}
void heapsort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n&&a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
int binarysearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		if (x > a[mid])
			left = mid + 1;
		else
			right = mid + 1;
	}
	return -1;
}
int main()
{
	int x, chon, left, right;
	char tt;
	do {
		system("cls");
		cout << "1.Khoi tao danh sach ngua nhien\n"
			<< "2.Nhap vao danh sach bang tay\n"
			<< "3.Xuat danh sach luu tru\n"
			<< "4.Sap xep danh sach bang Selectionsort\n"
			<< "5.Sap xep danh sach bang Interchagesort\n"
			<< "6.Sap xep danh sach bang insertionsort\n"
			<< "7.Sap xep danh sach bang Bubblesort\n"
			<< "8.Sap xep danh sach bang Quicksort\n"
			<< "9.Sap xep danh sach bang Heapsort\n"
			<< "10.Tim kiem phan tu X bang phuong phap tuan tu\n"
			<< "11.Tim kiem phan tu X bang phuong phap nhi phan\n";
		cout << "Nhap de thu hien: ";
		cin >> chon; \
			switch (chon)
			{
			case 1:
				khoitaonn(a, n);
				cout << "Khoi tao danh sach thanh cong\n";
				break;
			case 2:
				nhap(a, n);
				break;
			case 3:
				cout << "Danh sach dang luu tru: ";
				xuat(a, n);
				break;
			case 4:
				selectionsort(a, n);
				cout << "Danh sach sau khi sap xep bang Selectionsort la: ";
				xuat(a, n);
				break;
			case 5:
				interchange(a, n);
				cout << "Danh sach sau khi sap xep bang Interchangesort la: ";
				xuat(a, n);
				break;
			case 6:
				bubblesort(a, n);
				cout << "Danh sach sau khi sap xep bang Bubblesort la: ";
				xuat(a, n);
				break;
			case 7:
				selectionsort(a, n);
				cout << "Danh sach sau khi sap xep bang Selectionsort la: ";
				xuat(a, n);
				break;
			case 8:
				left = 0;
				right = n - 1;
				quicksort(a, left, right);
				cout << "Danh sach sau khi sap xep bang Quicksort la: ";
				xuat(a, n);
				break;
			case 9:
				heapsort(a, n);
				cout << "Danh sach sau khi sap xep bang Heapsort la: ";
				xuat(a, n);
				break;
			case 10:
				cout << "Nhap gia tri x can tim: ";
				cin >> x;
				if (search(a, n, x))
					cout << x << " co trong danh sach\n";
				else
					cout << x << " khong co trong danh sach luu tru\n";
				break;
			case 11:
				cout << "Nhap gia tri x can tim: ";
				cin >> x;
				if (binarysearch(a, n, x))
					cout << x << " co trong danh sach\n";
				else
					cout << x << " khong co trong danh sach luu tru\n";
				break;
			}
		cout << endl;
		cout << "Ban co muon tiep tuc (Y/N): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
}