#include<iostream>
using namespace std;
#define MAX 100
//=================================
struct Node
{
	int info;
	Node* link;
}
Node* first;
//=================================
void init()
{
	first=NULL;
}
//=================================
void insert_last(int x)
{
	Node*p=new Node;
	p->info=x;
	p->link=NULL;
	
	if(first==NULL)
	{
		first=p;
		return;
	}
	
	Node* i=first;
	while(i->link != NULL)
	{
		i=i->link;
	}
	i->link=p;
}
//=================================
void KhoiTaoDS()
{
	int x;
	do
	{
		cout<<"Nhap danh sach( 0 la dung): ";
		cin>>x;
		if(x!=0)
			insert_last(x);
	}while(x!=0);
}
//=================================
void output()
{
	for(Node* i=first; i!=NULL; i=i->link)
	{
		cout<<i->info<<"\t";
	}
}
//=================================

//=================================

//=================================

//=================================
int main()
{	
	int chon;
	system("cls");
	cout <<"3.1 Khai bao cau truc danh sach" << endl;
	cout <<"3.2 Khoi tao danh sach" << endl;
	cout <<"3.3 Xuat cac phan tu trong danh sach" << endl;
	cout <<"3.4 Tim mot phan tu trong danh sach" << endl;
	cout <<"3.5 Them mot phan tu vao dau danh sach" << endl;
	cout <<"3.6 Xoa mot phan tu dau danh sach" << endl;
	cout <<"3.7 Them mot phan tu cuoi danh sach" << endl;
	cout <<"3.8 Xoa mot phan tu cuoi danh sach" << endl;
	cout<<"3.9 Tim phan tu. Neu thaya, xoa"<<end;
	cout<<"3.10 Chuyen thanh danh sach co thu tu"<<endl<<endl;

	cout << "0.Thoat" << endl;
	do
	{
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout<<"Khai bao cau truc danh sach thanh cong!"<<endl;
			break;
		case 2:
			KhoiTaoDS();
			break;
		case 3:
			output();
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		case 10:
			
			break;
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");
	return 0;
}

