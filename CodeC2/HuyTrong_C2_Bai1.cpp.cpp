//
#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void nhap(int n,int a[])
{
	for(int i=0;i<=n-1;i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}
void xuat(int n,int a[])
{
	for(int i=0;i<=n-1;i++)
	{
		cout << a[i] << "\t";
	}
}
int Tim(int n,int a[],int x)
{
	int i=0;
	while(a[i]!=x && i<n)
		i++;
	if(i==n)
		return -1;
	else
		return i;
}
void ThemCuoi(int &n,int a[],int x)
{
	if(n<MAX)
	{
		a[n]=x;
		n++;
	}
	else
		cout << "Vuot qua so phan tu toi da cua danh sach" << endl;
}
void XoaCuoi(int &n,int a[])
{
	n--;
}
void XoaTaiI(int &n,int a[],int x)
{
	if(x<=n && x>=0)
	{
		for(int j=x;j<=n-1;j++)
			a[j]=a[j+1];
		n--;
	}
	else
		cout << "Vi tri khong phu hop" << endl;
}
void ThemTaiI(int &n,int a[],int x,int y)
{
	if(x>=0 && x<n)
	{
		for(int j=n-1;j>=x;j--)
			a[j+1]=a[j];
		a[x]=y;
		n++;
	}
	else
		cout << "Vi tri khong phu hop" << endl;
}
void XoaPtTim(int &n,int a[],int x)
{
	for(int i=0;i<=n-1;i++)
		if(a[i]==x)
			for(int j=i;j<n;j++)
			{
				a[j]=a[j+1];
				n--;
			}
}
int main()
{
	int chon;
	int k,x,y,z,m,n,l;
	do{
	cout << "Nhap so phan tu cua danh sach dac: ";
	cin >> n;
	if(n<=0 || n>MAX)
		cout << "Nhap sai.Nhap lai\n";
	}while(n<=0 || n>MAX);
	cout << "Nhap phan tu cho danh sach: ";
	nhap(n,a);
	do{
	cout << "Nhap yeu cau:\n";
	cout << "1. Xuat danh sach ra man hinh.\n";
	cout << "2. Tim mot phan tu trong danh sach.\n";
	cout << "3. Them mot phan tu vao cuoi danh sach.\n";
	cout << "4. Xoa phan tu cuoi danh sach.\n";
	cout << "5. Xoa phan tu thu i trong danh sach.\n";
	cout << "6. Them mot phan tu vao danh sach tai vi tri i.\n";
	cout << "7. Tim mot phan tu trong danh sach.Neu tim thay xoa phan tu.\n";
	cout << "8. Thoat\n";
	cin >> chon;
	if(chon<1 || chon>8)
		cout << "Chon khong thich hop.Chon lai!!!\n";
	else
	switch(chon)
	{
		case 1:
			cout << "Cac phan tu trong danh sach: ";
			xuat(n,a);
			cout << endl;
			break;
		case 2:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if(Tim(n,a,x)==-1)
				cout << x << " khong co trong danh sach.";
			else
				cout << x << " co trong danh sach o vi tri: " << Tim(n,a,x) << endl;
			break;
		case 3:
			cout << "Nhap phan tu can them: ";
			cin >> y;
			ThemCuoi(n,a,y);
			cout << "Danh sach phan tu sau khi them: ";
			xuat(n,a);
			cout << endl;
			break;
		case 4:
			XoaCuoi(n,a);
			cout << "Danh sach phan tu sau khi xoa: ";
			xuat(n,a);
		case 5:
			cout << "Nhap vi tri can xoa: ";
			cin >> z;
			XoaTaiI(n,a,z);
			cout << "Danh sach phan tu sau khi xoa: ";
			xuat(n,a);
			cout << endl;
			break;
		case 6:
			cout << "Nhap phan tu can them: ";
			cin >> m;
			cout << "Nhap vi tri can them: ";
			cin >> k;
			ThemTaiI(n,a,k,m);
			cout << "Danh sach phan tu sau khi them: ";
			xuat(n,a);
			cout << endl;
			break;
		case 7:
			cout << "Nhap phan tu can tim de xoa: ";
			cin >> l;
			XoaPtTim(n,a,l);
			cout << "Danh sach phan tu: ";
			xuat(n,a);
			cout << endl;
			break;
		case 8:
			break;
	}
		}while(chon!=8 || chon<1 || chon>8);
	system("pause");
	return 0;
}