#include <iostream>
#include<stdio.h>
using namespace std;
// khai bao cau truc phan tu danh sach lien ket kep
struct Node{
	int c;
	int power;
	Node* prev;
	Node* next;
};

	Node * first;
	Node * last;
	// Khoi tao danh sach lien kep
	void init()
	{
		first = NULL;
		last = NULL;
	}
	// Them phan tu vao DSLK Kep
	int Insert( Node *p)
	{
		if(first == NULL)
		{
			first = p;
			last = p;
			return 1;
		}
		else
		{
			Node * q = first;
			while(q!=NULL)
			{
				if(q ->power == p ->power)
					break;
				q = q ->next;
			}
			if(q!= NULL)
				q->c += p ->c;
			else
			{
				
				
				p ->prev = last;
				p ->next = NULL;
				last->next = p;
				last = p;
				return 1;
			}
		}
	return 0;
	}
	void output()
	{
		if(first == NULL)
		{
			cout << "Da thuc rong!!!\n";
			return;
		}
		cout << "Da thuc: \n";
		Node *p = first;
		while(p != NULL)
		{
			// neu c = 0 thi khong xuat


			if(p ->c == 0)
				cout << "";
			else
			{ 
				// neu là phan tu dau tien thi khong xuat dau
				if(p == first)
					if(p->c > 0)
						if(p -> c == 1)
							cout << "";
						else
							cout << p ->c;
					else
						if(p->c == -1)
							cout << "-";
						else
							cout << "-" << 0 - p->c;
				else
					// xuat dau
					if(p ->c < 0)
						if(p->c == -1)
							cout << "-";
						else
							cout << "-"  <<  0 - p->c;
					else
						if(p->c == 1)
							cout << "+";
						else
							cout << "+"  << p->c;
				// neu power > 1 thi xuat x^(power), neu power = 1 thi xuat x,neu power = 0 thi ko xuat 
				if(p -> power > 1)
					cout << "X^(" << p ->power << ")";
				else
					if(p ->power == 1)
						cout << "X";
				cout << "\t";
			}
			p = p-> next;
		}		
	}
int main()
{
	int choice;
	int c, power;
	
	system("cls");
	cout << "   ------------- BIEU DA THUC BANG DSLK KEP(CHUONG 2, BAI 14----------------  \n";
	cout << "1. Khoi tao danh sach.\n";
	cout << "2. chen phan tu vao da thuc.\n";
	cout << "3. Xuat da thuc ra man hinh.\n";
	cout << "4. Thoat.\n";
	

	do{
		Node *p = new Node;
		cout << "\n   Moi ban chon so de thuc hien: ";
		cin  >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "Da khoi tao mang thanh cong.\n";
				break;
			case 2:
				cout << "Nhap vao c va power: ";
				cin >> c >> power;
				p->c = c;
				p->power = power;
				int a  = Insert(p);
				output();
				
				break;
			case 3:
				output();
				break;
			case 4:
				cout << "Goodbye!\n";
				break;
		}
	}while(choice != 4);
	
	
	system("pause");
return 0;
}