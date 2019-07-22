#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int sp;
void init(int a[],int &sp)
{
	sp=-1;
}
int isFull(int a[],int sp)
{
	if(sp == MAX-1)
		return 1;
	return 0;
}
int isEmpty(int a[],int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
void Push(int a[],int &sp,int x)
{
	if(sp < MAX-1)
	{
		a[++sp]=x;
	}
}
int Pop(int a[],int &sp)
{
	if(sp==-1)
	{
		cout << "Ngan xep rong\n";
		return -1;
	}
	return a[sp--];
}
int main()
{
	{
    init(a,sp);
    int m,k;
    cout << "Chuong trinh chuyen doi thap phan sang nhi phan!" << endl;
    do
    {
        cout << "Nhap so thap phan can chuyen: ";
        cin >> m ;
    }
    while (m<=0);
    while (m!=0)
    {
        k=m%2;
        Push(a,sp,k);
        m=m/2;
    }
    cout << "So nhi phan la: ";
    while (isEmpty(a,sp)==0)
        cout << Pop(a,sp);
	cout << endl;
	system("pause");
	return 0;
	}
}