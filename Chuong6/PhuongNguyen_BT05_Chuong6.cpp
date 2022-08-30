//BT05_Chuong 6
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iomanip>
using namespace std;

//khai bao ma tran bang mang hai chieu
#define MAX 20
int a[MAX][MAX];
int n; // so dinh cua do thi
char vertex[MAX];  // ten dinh

void InitGraph()
{
	n = 0;
}

//Nhap ma tran tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "\nNhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//Nhap Graph tu file
void inputGraphFromText()
{
	string line;
	ifstream myfile("MTDT.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}
// Xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}

//khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // So phan tu tap E
			//Khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // so phan tu cua tap T

int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < n; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void XoaViTriE(int i)
{
	for (int j = 0; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}
int XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
	{
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
	}
}
void kruskal()
{
	for(int i=0;i<nE;i++)
	{
		if(TonTai(E1[i], T1, nT)==1  && TonTai(E2[i], T2, nT)==1)
			continue;
		if (TonTai(E1[i], T2, nT)==1  && TonTai(E2[i], T1, nT)==1)
			continue;
		T1[nT]=E1[i];
		T2[nT]=E2[i]; 
		wT[nT]=wE[i]; 
		nT++;
		if(nT==n-1)
		break;
	}
}
// Xuat ten dinh
void output(bool VertexName)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (VertexName)
			cout << endl << ")" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong= " << tong;
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "====BAI TAP 5, CHUONG 6, TIM KIEM CAY KHUNG TOI THEU, PRIM=======" << endl;
	cout << "1. Khoi tao ma tran ke rong" << endl;
	cout << "2. Nhap ma tran ke tu file text" << endl;
	cout << "3. Nhap ma tran ke" << endl;
	cout << "4.Xuat ma tran ke" << endl;
	cout << "5.Tim cay khung toi thieu bang Kruskal" << endl<<endl;
	cout << "0.Thoat\n";
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "Khoi tao thanh cong"<<endl;
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap ma tran ke tu file"<<endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			cout << "Nhap ma tran ke tu file"<<endl;
			outputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			kruskal(x);
			cout << "Cau khung toi thieu voi Kruskal"<<endl;
			output(true);
			break;
		default:
			choice=0;
		}
	} while (choice != 0);
	system("pause");
	return 0;
}
