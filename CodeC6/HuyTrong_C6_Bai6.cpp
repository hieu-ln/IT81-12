#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void initGraph()
{
	n = 0;
}
void inputGraph()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i<n; i++)
		cin >> vertex[i];
	for (int i = 0; i<n; i++)
	{
		cout << "Nhap vao dong thu: " << i + 1 << ": ";
		for (int j = 0; j<n; j++)
			cin >> a[i][j];
	}
}
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

int tontai(int d, int D[], int nD)
{
	for (int i = 0; i<n; i++)
	if (D[i] == d)
		return 1;
	return 0;
}
void swap(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}
void taoE()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	if (a[i][j] != 0)
	{
		E1[nE] = i;
		E2[nE] = j;
		wE[nE] = a[i][j];
		a[i][j] = 0;
		a[j][i] = 0;
		nE++;
	}

}
void sapxepE()
{
	for (int i = 0; i < nE; i++)
	for (int j = i + 1; j < nE; j++)
	if (wE[i] > wE[j])
	{
		swap(wE[i], wE[j]);
		swap(E1[i], E1[j]);
		swap(E2[i], E2[j]);
	}
}
void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (tontai(E1[i], T1, nT) == 1 && tontai(E2[i], T2, nT) == 1)
			continue;
		if (tontai(E1[i], T2, nT) == 1 && tontai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}
void output(bool vertexname)
{
	int tong = 0;
	for (int i = 0; i<nT; i++)
	{
		if (vertexname)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong=" << tong;
}
int main()
{
	int chon, x;
	cout << "Menu:\n";
	cout << "1.Khoi tao ma tran ke rng\n"; 
	cout << "2.Nhap ma tran ke\n"; 
	cout << "3.Xuat ma tran ke\n"; 
	cout << "4.Tim cay khung toi tieu bang KRUSKAL\n"; 
	cout << "5.Thoat\n"; 
	do{
		cout << "Ban chon:\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao ma tran ke rong thanh cong!";
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			taoE();
			sapxepE();
			kruskal();
			cout << "Cay khung toi tieu bang Kruskal cai tien: " << endl;
			output(true);
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (chon != 5);
	return 0;
}