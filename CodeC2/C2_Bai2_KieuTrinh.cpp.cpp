#include<iostream>
#include<ctime>
using namespace std;

//Cau 2.1
#define MAX 100
int a[MAX];
int n;
//Khoi tao danh sach
void input(int a[], int& n)
{
	do
	{
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Vui long nhap lai!\n";
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}

//Cau 2.2 Them phan tu
int insert_i(int a[], int& n, int x, int i)
{
	if (i <= n && i >= 0)
	{
		for (int j = n; j > i; j--)
			a[j] = a[j - 1];
		a[i] = x;
		n++;
		return 1;
	}
	return 0;
}
//Cau 2.3Xuat danh sach
void output(int a[], int n)
{
	cout << "Danh sach cac phan tu la: \n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//Cau 2.4(tim kiem tuan tu)
int Search(int a[], int n, int x)
{
	int i=0;
	while(i<n &&a[i]!=x)
		i++;
	if(i==n)
		return -1;
	return i;	
}
//Độ phức tạp của thuật toán: O(n)

//Cau 2.5(tim kiem nhi phan)
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a [mid] == x)
			return mid;
		if(x > a[mid]) 
			left = mid + 1;
		else right = mid-1;
	}
	return -1; // không tìm thấy x trong danh sách a;
}
//Độ phức tạp của thuật toán: O(log n).

//Xóa phần tử tại vị trí i
int Delete(int a[], int &n, int i)
{
	if(i>=0 && i<n)
	{
		for(int j=i; j<n-1; j++)
		{
			a[j]=a[j+1];
		}
		n--;
		return 1;
	}
	return 0;
}
//Cau 2.6
int searchanddelelte( int a[], int &n,int x)
{
	for(int i=0; i<n;i++)
	{
		if(a[i]==x)
		{
			Delete(a,n,i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	clock_t start;
	double duration;
	int choice, x, i, b;
	input(a,n);
	system("cls");
	cout << " --------- BAI TAP 2 , CHUONG 2 , CAU TRUC DU LIEU CO BAN --------- " << endl;
	cout<< "1.Khai bao cau truc danh sach\n";
	cout<< "2.Them mot phan tu vao danh sach\n";
	cout<< "3.Xuat cac phan tu\n";
	cout<< "4.Tim mot phan tu(tim kiem tuan tu)\n";
	cout<< "5.Tim mot phan tu(Tim kiem cay nhi phan)\n";
	cout<< "6.Tim va xoa\n";
	cout<< "7.Thoat\n";
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "Khai bao thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			cout << "Ban muon them tai vi tri: ";
			cin >> i;
			if (i >= 0 || i < MAX)
			{
				b = insert_i(a, n, x, i);
				if (b == 1)
				{
					cout << "Them thanh cong!\n";
					output(a, n);
				}
				else
					cout << "Them khong thanh cong!\n";
			}
			else
				cout << "Vi tri khong hop le!\n";
			break;
		case 3:
			output(a, n);
			break;
		case 4:
			start = clock();
			cout<<"Nhap x: ";
			cin >> x;
			i = Search(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == - 1)
				cout << "Khong tim thay x= " << x << " trong day!" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl; 
			if(duration > 0)
				cout << "Thoi gian tim kiem tuan tu: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 5:
			start = clock();
			cout << "Nhap x: ";
			cin >> x;
			i = BinarySearch(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == - 1)
				cout << "Khong tim thay x= " << x << " trong day!" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl; 
			if(duration > 0)
				cout << "Thoi gian tim kiem nhi phan: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 6:
			cout<<"Vui long nhap gia tri can xoa x=";
			cin>>x;
			i =searchanddelelte(a,n,x);
			if(i==1)
			{
				cout<<"Xoa thanh cong!"<<endl;
				cout<<"Danh sach sau khi xoa la: \n";
				output(a,n);
			}
			else
				cout<<"Khong co phan tu nao de xoa! "<<endl;
			break;
		default:
			cout << "Goodbye!\n";
			break;
		}
	}while(choice!=7);
	system("Pause");
	return 0;
}

