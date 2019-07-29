#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
//cau 1.1
#define MAX 5000
int a[MAX];
int n;
//cau 1.2
void init(int a[], int& n)
{
	cout << "Nhap vao so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da duoc nhap ngau nhien la:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "Nhap vao cac phan tu trong danh sach:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
//cau 1.3
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void copyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//cau 1.4
void insertionSort(int a[], int n)
{
	int i, j, key;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + i] = key;
	}
}
// ham hoan doi
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
//cau 1.5
void selectionSort(int a[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}
//cau 1.6
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
//cau 1.7
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++)
	{
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				haveSwap = true;
			}
		if (haveSwap == false)
			break;
	}
}
//cau 1.8
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot)
			left++;
		while (right >= left && a[right] > pivot)
			right--;
		if (left >= right)
			break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}
// ham quick sort
void quickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
}
//cau 1.9
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
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void heapSort(int a[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		shift(a, i, n);
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
// cau 1.10
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "Khong tim thay\n";
	else
		cout << "Tim thay tai vi tri " << i << endl;
}
//cau 1.11
int searchBinary(int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = 1 + (r - 1) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchBinary(a, mid + 1, r, x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "-----------MENU----------\n";
	cout << "1. Khoi tao danh sach ngau nhien\n";
	cout << "2. Nhap danh sach\n";
	cout << "3. Xuat danh sach\n";
	cout << "4. Xep thu tu danh sach bang selection sort\n";
	cout << "5. Xep thu tu danh sach bang insertion sort\n";
	cout << "6. Xep thu tu danh sach bang bubble sort\n";
	cout << "7. Xep thu tu danh sach bang interchange sort\n";
	cout << "8. Xep thu tu danh sach bang quick sort\n";
	cout << "9. Xep thu tu danh sach bang heap sort\n";
	cout << "10. Tim kiem phan tu x bang tim kiem tuan tu\n";
	cout << "11. Tim kiem phan tu x bang tim kiem nhi phan\n";
	cout << "12. Thoat\n";
	do {
		cout << "Vui long chon de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, n);
			break;
		case 2:
			input(a, n);
			break;
		case 3:
			cout << "Danh sach la:\n";
			output(a, n);
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi Selection sort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Selection Sort: " << duration * 1000000 << " Microseconds\n";
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi Selection sort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Insertion Sort: " << duration * 1000000 << " Microseconds\n";
			break;
		case 6:
			copyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi Selection sort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Bubble Sort: " << duration * 1000000 << " Microseconds\n";
			break;
		case 7:
			copyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi Selection sort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Interchange Sort: " << duration * 1000000 << " Microseconds\n";
			break;
		case 8:
			copyArray(a, b, n);
			start = clock();
			quickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi Selection sort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Quick Sort: " << duration * 1000000 << " Microseconds\n";
			break;
		case 9:
			copyArray(a, b, n);
			start = clock();
			heapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi Selection sort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Heap Sort: " << duration * 1000000 << " Microseconds\n";
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			searchSequence(b, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000 << " Microseconds\n";
			break;
		case 11:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchBinary(b,0, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = " << x << " trong day!\n";
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000 << " Microseconds\n";
			break;
		case 12:
			cout << "GOOBYE.....!!!\n";
			break;
		default:
			break;
		}
	} while (choice != 12);
	system("pause");
	return 0;
}