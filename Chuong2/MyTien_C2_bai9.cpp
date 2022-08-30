#include<iostream>
using namespace std;

struct ThTin
{
    int n; // so luong dia
    char dau, dich, trgian;
};

struct Node {
	ThTin info;
	Node* link;
};

Node* sp;

//===============================================
void init() {
	sp = NULL;
}

int isEmpty() {
	if (sp == NULL)
		return 1;
	return 0;
}

int Push(ThTin x) {
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}

int Pop(ThTin& x) {
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}   
//===============================================
void Tower(ThTin x)
{
    ThTin tam;
    int solan=1;
    
    init();
    Push(x);
    do{
        Pop(x);
        if(x.n ==1) cout<<"Lan thu: "<< solan++ <<"\t Chuyen dia tu cot "<< x.dau <<" sang cot "<< x.dich <<endl;
        else
        {   // Luu Tower( n-1, c, b, a);
            tam.n = x.n-1;
            tam.dau = x.trgian;
            tam.dich = x.dich;
            tam.trgian = x.dau;
            Push(tam);
            
            // Luu Tower( 1, a, b, c);
            tam.n = 1;
            tam.dau = x.dau;
            tam.dich = x.dich;
            tam.trgian = x.trgian;
            Push(tam);
            
            // Luu Tower( n-1, a, c, b);
            tam.n = x.n-1;
            tam.dau = x.dau;
            tam.dich = x.trgian;
            tam.trgian = x.dich;
            Push(tam);
        }
    }while(!isEmpty());

}
int main(){

    ThTin thap = {3, 'A', 'B', 'C'};
    
    Tower(thap);
}
