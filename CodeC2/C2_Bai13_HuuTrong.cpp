#include <iostream>
using namespace std;
#define max 100
typedef double dathuc[max];
dathuc a;
int n;
void nhapdathuc(dathuc &a, int &n)
{
	do {
		cout << "Nhap bac cua da thuc: ";
		cin >> n;
		if (n < 1)
			cout << "Bac cua da thuc phai lon hon 1. Nhap lai.";
	} while (n < 1);
	for (int i = 0; i <= n; i++)
	{
		cout << "Nhap he so cua bac " << i << ": ";
		cin >> a[i];
	}
}
void xuatmu(int i)
{
	if (i == 1) cout << "*X";
	else if (i > 1) cout << "*X^" << i;
}
void xuatdathuc(dathuc a, int n)
{
	int i = n;
	while (a[i] == 0 && i >= 0) i--;
	cout << a[i]; xuatmu(i);
	while (--i >=0)
	{
		if (a[i] > 0) { cout << " + " << a[i]; xuatmu(i); }
		else if (a[i] < 0) { cout << " - " << -a[i]; xuatmu(i); }
	}
}
void cong(dathuc P, int n, dathuc Q, int m)
{
	dathuc K; int i, o = (m > m) ? m : n;
	for (i = 0; i <= m && i <= n; i++)
		K[i] = P[i] + Q[i];
	if (m > n)
		while (i <= o) { K[i] = P[i]; i++; }
	else
		while (i <= o) { K[i] = Q[i]; i++; }
	cout << "\nP(x)+ Q(x) = "; xuatdathuc(K, o);
}
void hieu(dathuc P, int m, dathuc Q, int n)
{
	dathuc K; int i, o = (m > m) ? m : n;
	for (i = 0; i <= m && i <= n; i++)
		K[i] = P[i] - Q[i];
	if (m > n)
		while (i <= o) { K[i] = P[i]; i++; }
	else
		while (i <= o) { K[i] = -Q[i]; i++; }
	cout << "\nP(x) - Q(x) = "; xuatdathuc(K, o);
}
void tich(dathuc P, int m, dathuc Q, int n)
{
	dathuc K; int i, j, o = m + n;
	for (i = 0; i <= o; i++) K[i] = 0;
	for (i = 0; i <= m; i++)
		for (j = 0; j <= n; j++)
			K[i + j] += P[i] * Q[j];
	cout << "\nP(x) * Q(x) = "; xuatdathuc(K, o);
}
void thuong(dathuc p, int n, dathuc q, int m) {
	int i, j, z, x;
	double r[max], du[max];
	for (i = 0; i <= n; i++) du[i] = p[i];
	if (n < m) cout << 0 << "\n";
	else {
		x = n;
		z = n - m;
		if (n == m) { r[z] = p[n] / q[n]; z++; }
		else {
			while (z >= 0) {
				r[z] = du[x] / q[m];
				int y = m;
				for (i = x; i >= x - m; i--) {
					du[i] = du[i] - r[z] * q[y];
					y--;
				}
				x--;
				z--;
			}
		}
	}
	cout << "Da thuc R=P/Q: ";
	for (i = n - m; i >= 0; i--) {
		if (i == 0) cout << r[0] << "\n";
		else if (r[i] != 0) cout << r[i] << "*x^" << i << "+";
	}
	cout << "da thuc du: ";
	for (i = x; i >= 0; i--) {
		if (i == 0) cout << du[0] << "\n";
		else if (du[i] != 0) cout << du[i] << "*x^" << i << "+";

	}
}
int main()
{
	dathuc p, q;
	int m, chon;
	char tt;
	do {
		system("cls");
		cout << "1. Nhap 2 da thuc P(x) va Q(x)\n2. Xuat 2 da thuc P(x) va Q(x)\n3. Cong 2 da thuc P(x) va Q(x)\n4. Tru 2 da thuc P(x) va Q(x)\n5. Nhan 2 da thuc P(x) va Q(x)\n6. Chia 2 da thuc P(x) va Q(x)\n";
		cout << "Chon de thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap da thuc P(x): ";
			nhapdathuc(p, n);
			cout << "Nhap da thuc Q(x): ";
			nhapdathuc(q,m);
			break;
		case 2:
			cout << "\nP(x)= ";
			xuatdathuc(p, n);
			cout << "\nQ(x)= ";
			xuatdathuc(q, m);
			break;
		case 3:
			cout << "Tong 2 da thuc: ";
			cong(p, n, q, m);
			break;
		case 4:
			cout << "Hieu 2 da thuc: ";
			hieu(p, n, q, m);
			break;
		case 5:
			cout << "Tich 2 da thuc: ";
			tich(p, n, q, m);
			break;
		case 6:
			cout << "Chia 2 da thuc: \n";
			thuong(p, n, q, m);
			break;
		default:
			break;
		}
		cout << "\nBan co muon tiep tuc (Y/N): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
}