//#include <iostream>
//using namespace std;
//#define max 100
//int a[max];
//int sp;
//void khoitao(int a[],int &sp)
//{
//	sp=-1;
//}
//int ktrong(int a[],int sp)
//{
//	if (sp==-1)
//		return 1;
//	return 0;
//}
//int ktday(int a[],int sp)
//{
//	if (sp==max-1)
//		return 1;
//	return 0;
//}
//int them(int a[],int &sp,int x)
//{
//	if (sp<max-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
//int xoa(int a[],int &sp,int &x)
//{
//	if (sp!=-1)
//	{
//		x=a[sp--];
//		return 1;
//	}
//	return 0;
//}
//int Dec_Bin(int so)
//{
//	khoitao(a,sp);
//	int bin=0;
//	while (so!=0)
//	{
//		int du=so%2;
//		if (them(a,sp,du))
//			so/=2;
//		else
//			break;
//	}
//	while (!ktrong(a,sp))
//	{
//		int x;
//		if (xoa(a,sp,x))
//			bin=bin*10+x;
//		else
//			break;
//	}
//	return bin;
//}
//void xuat(int a[],int sp)
//{
//	for (int i=sp;i>=0;i--)
//		cout<<a[i]<<endl;
//}
//int main()
//{
//	char tt;
//	int chon;
//	system("cls");
//	cout<<"1. Khoi tao\n2. Kiem tra rong\n3.Kiem tra day\n4. Them mot phan tu\n5. Xoa phan tu\n6. Doi mot so nhi phan sang thap phan\n7. Xuat\n";
//	do{
//		cout<<"Chon de thuc hien: ";
//		cin>>chon;
//		switch (chon)
//		{
//		case 1:
//			khoitao(a,sp);
//			cout<<"Khoi tao thanh cong.\n";
//			break;
//		case 2:
//			if (ktrong(a,sp))
//				cout<<"Stack dang rong.\n";
//			else
//				cout<<"Stack khong rong.\n";
//			break;
//		case 3:
//			if (ktday(a,sp))
//				cout<<"Stack da day.\n";
//			else
//				cout<<"Stack chua day.\n";
//			break;
//		case 4:
//			int x;
//			cout<<"Nhap gia tri can them: ";
//			cin>>x;
//			if (them(a,sp,x))
//				cout<<"Them vao stack thanh cong.\n";
//			else
//				cout<<"Them vao stack khong thanh cong.\n";
//			break;
//		case 5:
//			int y;
//			if (xoa(a,sp,y))
//				cout<<"Xoa thanh cong. Phan tu vua xoa la "<<y<<endl;
//			else
//				cout<<"Xoa khong thanh cong.\n";
//			break;
//		case 6:
//			int dec;
//			cout<<"Nhap gia tri can doi sang nhi phan: ";
//			cin>>dec;
//			if (Dec_Bin(dec))
//				cout<<"Dang nhi phan cua "<<dec<<" la: "<<Dec_Bin(dec)<<endl;
//			break;
//		case 7:
//			cout<<"Du lieu stack dang luu tru: ";
//			xuat(a,sp);
//			break;
//		}
//		cout<<"\nBan co muon tiep tuc (chon Y/N):\n ";
//		cin>>tt;
//	}while(tt=='y'||tt=='Y');
//}