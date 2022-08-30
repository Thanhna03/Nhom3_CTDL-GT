#include<iostream>
#define max 100
using namespace std;
int a[max];
int sp;
void init(int a[], int &sp)
{
	sp=-1;
}
void output(int a[], int sp)
{
	for(int i=0; i<sp+1; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int empty(int a[], int sp)
{
	if(sp==NULL)
	{
		return 1;
	}
	return 0;
}
int full(int a[], int sp)
{
	if(sp==max-1)
	{
		return 1;
	}
	return 0;
}
int push(int a[], int &sp, int x)
{
	if(sp<max-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;
}
int pop(int a[], int &sp, int &x)
{
	if(sp!= -1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}
void menu(int a[], int &sp, int x)
{
	char choose;
	system("cls");
	cout << "-----Bai tap chuong 2 stack-----"<< endl;
	cout << "1.Khoi tao stack rong" << endl;
	cout << "2.Kem tra stack rong" << endl;
	cout << "3.Kiem tra stack day" << end;
	cout << "4.Them 1 phan tu vao stack" << endl;
	cout << "5.Xoa 1 phan tu khoi stack" << endl;
	cout << "6.Xuat stack" << endl;
	cout << "7.Thoat" << endl;
	cout << "Nhap lua chon cua ban: ";
	cin >> choose;
	switch(choose)
	{
	case 1: 
		{
		init(a, sp);
		cout << "Khoi tao stack rong thanh cong\n";
		break;
		}
	case 2:
		{
			if(empty(a, sp))
			{
				cout << "Stack rong\n";
			}
			else
				cout << "Stack khong rong\n";
			break;
		}
	case 3:
		{
			if(full(a, sp))
			{
				cout << "Stack day\n";
			}
			else
				cout << "Stack khong day\n";
			break;
		}
	case 4:
		{
			cout << "Nhap phan tu muon them vao stack: ";
			cin >> x;
			if(push(a, sp, x))
			{
				cout << "Them thanh cong\n";
				cout << "Stack sau khi xoa la: ";
				output (a, sp);
			}
			else
				cout << "Them khong thanh cong\n";
			break;
		}
	case 5:
		{
			if(pop(a, sp, x))
			{
				cout << "Xoa thanh cong\n";
			}
			else
				cout << "Xoa khong thanh cong\n";
			break;
		}
	case 6:
		{
			cout << "Stack hien tai la: ";
			output(a, sp);
			break;
		}
	case 7:
		{
			cout << "Chuong trinh ket thuc\n";
			return;
		}
	default:
		{
			cout << "Nhap sai, nhap lai\n";
			break;
		}
	}
		system("pause");
		return menu(a, sp, x);	
}
int main()
{
	int a[max];
	int sp, x=0;
	menu(a, sp, x);
	system("pause");
	return 0;
}