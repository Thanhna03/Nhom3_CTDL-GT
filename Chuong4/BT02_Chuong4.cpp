#include<iostream>
using namespace std;
//================================
struct Node
{
	int info;
	Node *left, *right;	
};
Node* root;
//================================
void empty()
{
	root=NULL;
}
//================================
Node *search(Node* p, int x)
{
	while(p!=NULL)
	{
		if(0->info==x)
		{
			return p;
		}
		else 
		{
			if(p->info > x)
				p=p->left;
			else
				p=p->right;
		}
	}
	return NULL;
}
//================================
int Delete(Node *&T, int x)
{
	if (T== NULL) return 0;
	 if (T->info = = x)
	{	
		Node *p = T; 
		if (T->left == NULL)
			T=T->right;
		else if (T -> right == NULL)
			T=T->left;
		else // có 2 con
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info<x) return Delete(T->right, x);
	if(T->info>x) return Delete(T->left, x);
}
//================================
void searchStandFor(node *&p, Node  *&q)
{
	 if (q->left = = NULL)
	{	
		p->info == q->info
		p = q;
		q  = q -> right;
	}
	else 
		 searchStandFor(p, q->left)
}

//================================
void duyetNLR(Node  *p)
{
	if (p != NULL)
	{           		
		cout<<p->info<<“ “;
		duyetLNR(p->left);
		duyetLNR(p->right);
	}
}

//================================
void duyetLRN(Node  *p)
{
	if (p != NULL)
	{	
		duyetLNR(p->left);
		duyetLNR(p->right);
		cout<<p->info<<“ “;
	}
}

//================================
void duyetNLR(Node  *p)
{
	if (p != NULL)
	{           		
		cout<<p->info<<“ “;
		duyetLNR(p->left);
		duyetLNR(p->right);
	}
}

//================================
void InsertNode(node *&p, int x)
{
	if (p == NULL)
	{	
		 p=new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL; 	
	}
	else 
	{
		if (p->info == x)
			return; // dã có node có giá tr? x
		else if (p -> info > x)
			return InsertNode(p -> left, x);
		else 
			return InsertNode(p -> right, x);		
	}
}

//================================
int main()
{
	int chon,x;
	system("cls");
	cout << "===========BAI TAP 02 _ CHUONG 4==========" << endl;
	cout << "2.1 Khai bao cau truc cay nhi phan tim kiem" << endl;
	cout << "2.2 Khoi tao cay rong" << endl;
	cout << "2.3 Them mot phan tu vao cay (khong dung de quy)" << endl;
	cout << "2.4 Tim mot phan tu trong cay (khong dung de quy)" << endl;
	cout << "2.5 Xoa mot nut trong cay (dung de quy)" << endl;
	cout << "2.6 Duyet cay theo thu tu NLR (dung stack)" << endl;
	cout << "2.7 Duyet cay theo thu tu LNR (dung stack)" << endl;
	cout << "2.8 Duyet cay theo thu tu LRN (dung queue)" << endl;

	cout << "0.Thoat" << endl;
	do
	{
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout<<"Khai bao cau truc thanh cong!"<<endl;
			break;
		case 2:
			cout<<"Khoi tao cay rong thanh cong!"<<endl;
			break;
		case 3:
			cout<<"Chon phan tu muon them vao cay: ";
			cin>>x;
			InsertNode(root,  x);
			break;
		case 4:
			cout<<"Chon phan tu can tim: ";
			cin>>x;
			search(root, x);
			break;
		case 5:
			cout<<"Chon phan tu can xoa: ";
			cin>>x;
			Delete(root,  x);
			break;
		case 6:
			duyetNLR(root);
			break;
		case 7:
			duyetNLR(root);
			break;
		case 8:
			duyetLRN(root);
			break;
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");
    
    return 0;
}
