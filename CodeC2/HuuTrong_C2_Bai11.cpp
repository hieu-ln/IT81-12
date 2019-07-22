//#include <iostream>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *front, *rear;
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void them(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (rear != NULL)
//		rear->link = p;
//	else
//		front = p;
//	rear = p;
//}
//int pop(int &x)
//{
//	if (front != NULL)
//	{
//		node *p = front;
//		x = p->info;
//		front = front->link;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void xuat()
//{
//	if (front != NULL)
//	{
//		node *p = new node;
//		p = front;
//		do
//		{
//			cout << p->info << endl;
//			p = p->link;
//		} while (p != NULL);
//	}
//}
//int main()
//{
//	char tt;
//	int chon;
//	system("cls");
//	cout << "1. Khoi tao\n2. Kiem tra rong\n3. Them mot phan tu\n4. Xoa phan tu\n5. Xuat\n";
//	do {
//		cout << "Chon de thuc hien: ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao thanh cong.\n";
//			break;
//		case 2:
//			if (isEmpty())
//				cout << "Stack dang rong.\n";
//			else
//				cout << "Stack khong rong.\n";
//			break;
//		case 3:
//			int x;
//			cout << "Nhap gia tri can them: ";
//			cin >> x;
//			them(x);
//			break;
//		case 4:
//			int y;
//			if (pop(y))
//				cout << "Xoa thanh cong. Phan tu vua xoa la " << y << endl;
//			else
//				cout << "Xoa khong thanh cong.\n";
//			break;
//		case 5:
//			cout << "Du lieu stack dang luu tru: ";
//			xuat();
//			break;
//		}
//		cout << "\nBan co muon tiep tuc (chon Y/N):\n ";
//		cin >> tt;
//	} while (tt == 'y' || tt == 'Y');
//}
