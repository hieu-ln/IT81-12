//#include <iostream>
//#include <iomanip>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *first;
//void khoitao()
//{
//	first = NULL;
//}
//void xuat()
//{
//	node*p;
//	p = first;
//	while (p != NULL)
//	{
//		cout << setw(3) << p->info;
//		p = p->link;
//	}
//}
//node *tim(int x)
//{
//	node *p = first;
//	while ((p != NULL) && (p->info != x))
//		p = p->link;
//	return p;
//}
//void themdau(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = first;
//	first = p;
//}
//void themcuoi(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (first == NULL)
//		first = p;
//	else
//	{
//		node *q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
//int xoadau()
//{
//	if (first != NULL)
//	{
//		node *p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int xoacuoi()
//{
//	if (first != NULL)
//	{
//		node*p, *q;
//		p = first; q = NULL;
//		if(p!=NULL)
//			while (p->link!=NULL)
//			{
//				q = p;
//				p = p->link;
//			}
//		if (p != first)
//			q->link = NULL;
//		else
//			first = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int xoanode(int x)
//{
//	if (tim(x) != 0)
//	{
//		node*t = tim(x);
//		if (t == first)
//		{
//			if (xoacuoi())
//				return 1;
//		}
//		else
//			if (t->link == NULL)
//			{
//				if (xoacuoi())
//					return 1;
//			}
//			else
//			{
//				node *q = first, *p = first;
//				while (p != t)
//				{
//					q = p;
//					p = p->link;
//				}
//				q->link = t->link;
//				delete t;
//				return 1;
//			}
//		return 0;
//	}
//}
//void sxtang()
//{
//	node*p = first, *q;
//	while (p->link != NULL)
//	{
//		q = p->link;
//		while (q!=NULL)
//			if (p->info > q->info)
//			{
//				int tam = p->info;
//				p->info = q->info;
//				q->info = tam;
//			}
//		q = q->link;
//	}
//	p = p->link;
//}
//void sxgiam()
//{
//	node*p = first, *q;
//	while (p->link != NULL)
//	{
//		q = p->link;
//		while (q != NULL)
//			if (p->info <
// q->info)
//			{
//				int tam = p->info;
//				p->info = q->info;
//				q->info = tam;
//			}
//		q = q->link;
//	}
//	p = p->link;
//}
//int main()
//{
//	khoitao();
//	int n, x, p;
//	cout << "Nhap so luong Node: ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "\nNhap gia tri cho Node thu " << i << ": ";
//		cin >> x;
//		themcuoi(x);
//	}
//	cout << "\nDanh sach dang luu tru: ";
//	xuat();
//	cout << "\nNhap gia tri can tim: ";
//	cin >> p;
//	if (tim(p))
//		cout << p << " ton tai trong danh sach, o vi tri " << tim(p);
//	else
//		cout << p << " khong co trong danh sach luu tru.";
//	cout << endl;
//	system("pause");
//	return 0;
//}