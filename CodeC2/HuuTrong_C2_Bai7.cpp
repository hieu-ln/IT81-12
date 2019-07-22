//#include <iostream>
//using namespace std;
//#define max 100
//int a[max];
//int front, rear;
//void init(int a[],int &front,int &rear)
//{
//	front=-1;
//	rear=-1;
//}
//int ktrong(int a[],int front,int rear)
//{
//	if (front==-1)
//		return 1;
//	return 0;
//}
//int ktday(int a[],int front,int rear)
//{
//	if (rear-front==max-1)
//		return 1;
//	return 0;
//} 
//int them(int a[],int &front,int &rear, int x)
//{
//	if (!ktday(a,front,rear))
//	{
//		if (front==-1)
//			front=0;
//		if (rear==max-1)
//		{
//			for (int i=front;i<=rear;i++)
//				a[i-front]=a[i];
//			rear=max-1-front;
//			front=0;
//		}
//		a[++rear]=x;
//		return 1;
//	}
//	return 0;
//}
//int xoa(int a[],int &front,int &rear,int &x)
//{
//	if (!(front==-1))
//	{
//		x=a[front++];
//		if (front>rear)
//		{
//			front=-1;
//			rear=-1;
//		}
//		return 1;
//	}
//	return 0;
//}
//void xuat(int a[],int front,int rear)
//{
//	for (int i=front;i<=rear;i++)
//		cout<<a[i]<<endl;
//}
//int main()
//{
//	char tt;
//	int chon;
//	system("cls");
//	cout<<"1. Khoi tao\n2. Kiem tra rong\n3.Kiem tra day\n4. Them mot phan tu\n5. Xoa phan tu\n6.Xuat\n";
//	do{
//		cout<<"Chon de thuc hien: ";
//		cin>>chon;
//		switch (chon)
//		{
//		case 1:
//			init(a,front,rear);
//			cout<<"Khoi tao thanh cong.\n";
//			break;
//		case 2:
//			if (ktrong(a,front,rear))
//				cout<<"Queue dang rong.\n";
//			else
//				cout<<"Queue khong rong.\n";
//			break;
//		case 3:
//			if (ktday(a,front,rear))
//				cout<<"Queue da day.\n";
//			else
//				cout<<"Queue chua day.\n";
//			break;
//		case 4:
//			int x;
//			cout<<"Nhap gia tri can them: ";
//			cin>>x;
//			if (them(a,front,rear,x))
//				cout<<"Them vao Queue thanh cong.\n";
//			else
//				cout<<"Them vao Queue khong thanh cong.\n";
//			break;
//		case 5:
//			int y;
//			if (xoa(a,front,rear,y))
//				cout<<"Xoa thanh cong. Phan tu vua xoa la "<<y<<endl;
//			else
//				cout<<"Xoa khong thanh cong.\n";
//			break;
//		case 6:
//			cout<<"Du lieu stack dang luu tru: \n";
//			xuat(a,front,rear);
//			break;
//		}
//		cout<<"\nBan co muon tiep tuc (chon Y/N): ";
//		cin>>tt;
//	}while(tt=='y'||tt=='Y');
//}