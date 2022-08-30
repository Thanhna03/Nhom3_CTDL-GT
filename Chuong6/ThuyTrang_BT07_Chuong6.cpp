//BT07_Chuong 6
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

void Prim(int s)
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for(int v= 0 ; v < n; v++)
			if(a[u][v] != 0)
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for(int i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for(; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
				if (min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1,d2);
		u = d2;
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
	int string=DoThi1;
	int choice, x, i;
	system("cls");
	cout << "====BAI TAP 7, CHUONG 6, TIM KIEM CAY KHUNG TOI THEU, PRIM=======" << endl;
	cout << "7.1 Xuat ma tran ke" << endl;
	cout << "7.2 Cay khung toi thieu bang thuat giai Prim" << endl;
	cout << "7.3 Cay khung toi thieu bang thuat giai Kruskal" << endl;
	cout << "7.4 Cay khung toi thieu bang thuat giai Kruskal duoc cai tien" << endl;
	cout << "0.Thoat\n";
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			outputGraph();
			break;
		case 2:
			Prim( s);
			break;
		case 3:
			kruskal();
			break;
		case 4:
			kruskal_cai_tien();
			break;
		default:
			choice=0;
		}
	} while (choice != 0);
	system("pause");
	return 0;
}
