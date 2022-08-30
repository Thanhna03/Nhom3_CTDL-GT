#include<iostream>
#include<stdio.h>
using namespace std;
//===================================
struct Node
{
	int info;
	Node* link;
};
Node* sp;
//===================================
void init()
{
	sp = NULL;
}
//===================================
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}

//===================================
int Pop(int& x)
{
	if (sp != NULL) // if(!isEmpty())
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//===================================
int Dec_TheoHeSo(int x, int heso)
{
	if (x >= 0 && (1 < heso && heso <= 16))
	{
		cout << "Voi he so " << heso << "cua DEC = " << x << " la: ";
		int du;
		do {
			du = x % heso;
			Push(du);
			x = x / heso;
		} while (x != 0);


		while (Pop(du) == 1)
		{
			if (du > 9) cout << char(du - 10 + 'A');
			else cout << du;
		}
		switch (heso)
		{
		case 2: cout << " Bin\n"; break;
		case 8: cout << " Oct\n"; break;
		case 16: cout << " Hex\n"; break;
		default: cout << " ???\n"; break;
		}
		return 1;
	}
	return 0;
}
//===================================
int main()
{
	int x, i, heso;
	cout << "Chuyen doi he thap phan sang he nhi phan";
	cout << "\nMoi nhap so thap phan duong: ";
	cin >> x;
	cout << "\nMoi nhap he so can chuyen doi: ";
	cin >> heso;
	i = Dec_TheoHeSo(x, heso);
	if (i == 0) cout << " Khong chuyen doi duoc\n";
	return 0;
}


