//#include <iostream>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *sp;
//void khoitao()
//{
//	sp=NULL;
//}
//int ktrong()
//{
//	if (sp==NULL)
//		return 1;
//	return 0;
//}
//void them(int x)
//{
//	node *p=new node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//int pop(int &x)
//{
//	if (sp!=NULL)
//	{
//		node *p=sp;
//		x=p->info;
//		sp=sp->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int convert(int tp)
//{
//	khoitao();
//	while (tp!=0)
//	{
//		int d=tp%2;
//		them(d);
//		tp/=2;
//	}
//	int np=0;
//	while (!ktrong())
//	{
//		int so;
//		if (pop(so))
//			np=np*10+so;
//	}
//	return np;
//}
//void xuat()
//{
//	node *p=new node;
//	p=sp;
//	while (p!=NULL)
//	{
//		cout<<p->info<<endl;
//		p=p->link;
//	}
//}
//int main()
//{
//	char tt;
//	int chon;
//	system("cls");
//	cout<<"1. Khoi tao\n2. Kiem tra rong\n3. Them mot phan tu\n4. Xoa phan tu\n5. Doi mot so nhi phan sang thap phan\n6. Xuat\n";
//	do{
//		cout<<"Chon de thuc hien: ";
//		cin>>chon;
//		switch (chon)
//		{
//		case 1:
//			khoitao();
//			cout<<"Khoi tao thanh cong.\n";
//			break;
//		case 2:
//			if (ktrong())
//				cout<<"Stack dang rong.\n";
//			else
//				cout<<"Stack khong rong.\n";
//			break;
//		case 3:
//			int x;
//			cout<<"Nhap gia tri can them: ";
//			cin>>x;
//			them(x);
//			break;
//		case 4:
//			int y;
//			if (pop(y))
//				cout<<"Xoa thanh cong. Phan tu vua xoa la "<<y<<endl;
//			else
//				cout<<"Xoa khong thanh cong.\n";
//			break;
//		case 5:
//			int dec;
//			cout<<"Nhap gia tri can doi sang nhi phan: ";
//			cin>>dec;
//			if (convert(dec))
//				cout<<"Dang nhi phan cua "<<dec<<" la: "<<convert(dec)<<endl;
//			break;
//		case 6:
//			cout<<"Du lieu stack dang luu tru: ";
//			xuat();
//			break;
//		}
//		cout<<"\nBan co muon tiep tuc (chon Y/N):\n ";
//		cin>>tt;
//	}while(tt=='y'||tt=='Y');
//}
