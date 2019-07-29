//
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout << a[i] << "\t";
	}
}
void swap(int &a,int &b)
{
	int tam=a;
	a=b;
	b=tam;
}
void SelectionSort(int a[],int n)
{
	int min_pos;
	for(int i=0;i<n-1;i++)
	{
		min_pos=i;
		for(int j=i+1;j<n;j++)
			if(a[j] < a[min_pos])
				min_pos=j;
		swap(a[i],a[min_pos]);
	}
}
void InsertionSort(int a[],int n)
{
	int x,j;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while(0<=j && x<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void BubbleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(a[j-1] > a[j])
				swap(a[j],a[j-1]);
}
void InterchangeSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[j]<a[i])
				swap(a[i],a[j]);
}
void QuickSort(int a[],int left,int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		QuickSort(a,left,j);
	if(i<right)
		QuickSort(a,i,right);
}
void Shift(int a[],int i,int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		Shift(a,j,n);
	}
}
void HeapSort(int a[],int n)
{
	int i=n/2-1;
	while(i>=0)
	{
		Shift(a,i,n);
		i--;
	}
	int right=n-1;
	while(right>0)
	{
		swap(a[0],a[right]);
		right--;
		if(right>0)
			Shift(a,0,right);
	}
}
int TimTuanTu(int a[],int n,int x)
{
	int i=0;
	while(i<n)
	{
		if(a[i]==x)
			return i;
		i++;
	}
	return 1;
}
int TimNhiPhan(int a[],int l,int r,int x)
{
	int i=(l+r)/2;
	if(x==a[i])
		return i;
	else
		if(x<a[i])
			return TimNhiPhan(a,0,n/2,x);
		else
			return TimNhiPhan(a,n/2,n,x);
	return 0;
}
int main()
{
	int chon,x,y;
	do{
	do{
	cout << "Menu:\n";
	cout << "1.Nhap danh sach.\n";
	cout << "2.Xuat danh sach.\n";
	cout << "3.Sap xep danh sach bang SelectionSort.\n";
	cout << "4.Sap xep danh sach bang InsertionSort.\n";
	cout << "5.Sap xep danh sach bang BubbleSort.\n";
	cout << "6.Sap xep danh sach bang InterchangeSort.\n";
	cout << "7.Sap xep danh sach bang QuickSort.\n";
	cout << "8.Sap xep danh sach bang HeapSort.\n";
	cout << "9.Dung phuong phap tim kiem tuan tu tim kiem 1 phan tu trong danh sach co thu tu.\n";
	cout << "10.Dung phuong phap tim kiem nhi phan tim kiem 1 phan tu trong danh sach co thu tu.\n";
	cout << "11.Thoat.\n";
	cout << "Ban chon:";
	cin >> chon;
	if(chon<1 || chon>11)
		cout << "Chon khong phu hop.Chon lai!\n";
	}while(chon<1 || chon>11);
	switch(chon)
	{
	case 1:
		system("cls");
		cout << "Nhap so luong phan tu trong danh sach:";
		cin>>n;
		nhap(a,n);
		cout << endl;
		break;
	case 2:
		system("cls");
		cout << "Cac phan tu trong danh sach:\n";
		xuat(a,n);
		cout << endl;
		break;
	case 3:
		system("cls");
		SelectionSort(a,n);
		cout << "Sap xep thanh cong!\n";
		break;
	case 4:
		system("cls");
		InsertionSort(a,n);
		cout << "Sap xep thanh cong!\n";
		break;
	case 5:
		system("cls");
		BubbleSort(a,n);
		cout << "Sap xep thanh cong!\n";
		break;
	case 6:
		system("cls");
		InterchangeSort(a,n);
		cout << "Sap xep thanh cong!\n";
		break;
	case 7:
		system("cls");
		QuickSort(a,0,n-1);
		cout << "Sap xep thanh cong!\n";
		break;
	case 8:
		system("cls");
		HeapSort(a,n);
		cout << "Sap xep thanh cong!\n";
		break;
	case 9:
		system("cls");
		cout << "Nhap phan tu muon tim trong danh sach: ";
		cin >> x;
		if(TimTuanTu(a,n,x)==1)
			cout << x << " khong co trong danh sach!\n";
		else
			cout << x << " co trong danh sach o vi tri thu " << TimTuanTu(a,n,x) << endl;
		break;
	case 10:
		system("cls");
		BubbleSort(a,n);
		cout << "Nhap phan tu muon tim kiem trong danh sach: ";
		cin >> y;
		if(TimNhiPhan(a,0,n,y)==0)
			cout << y << " khong co trong mang.\n";
		else
			cout << y << " co trong mang vi tri thu " << TimNhiPhan(a,0,n,y) << endl;
		break;
	case 11:
		system("cls");
		break;
	}
}while(chon>=1 && chon <11);
	system("pause");
	return 0;
}