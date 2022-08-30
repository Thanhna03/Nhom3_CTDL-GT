#include<stdio.h>
#include <iostream>
using namespace std;
#define COUNT 10
//1.1
struct Node{
	int info;
	Node* left;
	Node* right;
};
//1.2
void Init()
{
	root = NULL;
}
//1.3
int insert_node_recursive(int x, Node* q)
{
	if(q->info == x)
		return 0;
	else if(q->info>x)
	{
		if(q->left == NULL)
		{
			Node* p= new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return insert_node_recursive(x, q->left);
	}
	else
	{
		if(q->right == NULL)
		{
			Node *p= new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return insert_node_recursive(x, q->right);
	}
}

void insertNode(Node*& p, int x)
{
	if(p==NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{ 
		if(p->info == x)
			return ;
		else if(p->info >x)
			return insertNode(p->left, x);
		else
			return insertNode(p->right, x);

}
	//1.4
Node* Search(Node* p, int x)
{
	if(p!=NULL)
	{
		if(p->info== x)
			return p;
		else
			if( x> p->info)
				return Search(p->, x);
			else
				return Search(p->, x);
	}
	return NULL;
}
void Searchstandfor(Node*&p, Node*& q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p=q;
		q= q->right;
	}
	else
		Searchstandfor(p, q-> left);
}
int Delete(Node*& T, int x)
{
	if(T== NULL) return 0;
	if(T-> info == x)
	{
		Node* p = T;
		if(T->left == NULL)
			T = T->right;
		else if(T->right == NULL)
			T = T->left;
		else
			Searchstandfor(p, T->right);
		delete p;
		return 1;
	}
	if (T-> info < x) return Delete(T->right, x);
	if(T->info > x) return Delete(T->left, x);
}
void DuyetLNR(Node* p)
{
	if(p!=NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}
void DuyetNLR(Node* p)
{
	if(p!=NULL)
}