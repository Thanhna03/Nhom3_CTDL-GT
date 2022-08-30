#include <iostream>

using namespace std;
//============================================
struct Node
{
  int info;
  Node* link;
};
Node* first;
//============================================
void Init()
{
    first=NULL;
}
//============================================
void insert_last(int X)
{
    
    Node* p=new Node;
    p->info=X;
    p->link=NULL;
    
    if(first==NULL)
    {
        first=p;
        return;
    }
    
    Node* i=first;
    while(i->link!=NULL)
    {
        i=i->link;
    }
    i->link=p;
}
//============================================
void KhoiTao()
{
    int X;
    do{
        cout<<"Nhap danh sach( 0 la dung): ";
        cin>>X;
        if(X!=0) 
        {
            InsertLastList( X);
        }
    }while(X!=0);
}
//============================================
void output()
{
    for(Node* i=first;i!=NULL;i=i->link)
    {
        cout<<i->info<<"\t";
    }
}
//============================================
bool Del_last()
{
    if(first==NULL)
        return false;
        
    if(first->link==NULL)
    {
        delete first;
        first=NULL;
        return true;
    }
    Node*j;
    Node* i=first;
    while( i->link!=NULL)
    {
        j=i;
        i=i->link;
    }
    j->link=NULL;
    delete i;
    return true;
}
//============================================
Node* search(int x)
{
	Node* p=first;
	while((p!=NULL) && (p->info!=x))
		p=p->link;
	return p;
}
//============================================
int main()
{
	int chon;
	system("cls");
	cout << "===========BAI TAP 4 _ CHUONG 2==========" << endl;
	cout << "4.1 Khai bao cau truc danh sach" << endl;
	cout << "4.2 Khoi tao danh sach rong " << endl;
	cout << "4.3 Them phan tu vao danh sach" << endl;
	cout << "4.4 Xuat cac phan tu trong danh sach" << endl;
	cout << "4.5 Tim mot phan tu trong danh sach" << endl;
	cout << "4.6 Tim phan tu trong danh sach. Neu thay, xoa" << endl;

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
			cout<<"Khoi tao danh sach rong thanh cong!"<<endl;
			break;
		case 3:
			KhoiTao();
			break;
		case 4:
			output();
			break;
		case 5:
			int x;
			cout<<"Nhap phan tu can tim: ";
			cin>>x;
			Node* search(x);
			break;
		case 6:
			cout<<"Nhap phan tu can tim: ";
			cin>>x;
			Node* search(x);
			if(x==p) Del_last(p);
			break;
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");
    
    return 0;
}
