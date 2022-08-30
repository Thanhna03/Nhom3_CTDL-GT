#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<list>
using namespace std;
// khai bao ma tran bang mang hai chieu
#define Max 20
int a[Max][Max];
int n; //so dinh cua do thi
char vertex[Max]; // ten dinh

void InitGraph()
{
	n=0;
}
// Nhap Graph bang tay
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i+1 << ": ";
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	}
}
//Nhap graph tu file text
voi inputGraphFromText()
{
	ifstream myfile("mtts2.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i=0; i<n; i++)
			myfile >> vertex[i];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				myfile >> a[i][j];
		}
	}
}
// Xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << stew(6) << left;
		cout << endl;
	}
}
// Khai bao TapE
int E1[Max];
int E2[Max];
int wE[Max];
int nE=0; //so ptu tap E
// khai bao tap E
int T1[Max];
int T2[Max];
int wE[Max];
int nE=0; // So phan tu tap T

voidTaoE()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(a[i][j] !=0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j]=0;
				nE++;

			}
}
int Tontai(int E, int T[], int nT)
{
	for( int i=0; i<nT; i++)
	{
		if(E == T[i])
			return 1;
	}
	return 0;
}
void Swap(int &a, int &b)
{
	int c = a;
	a=b;
	b=c;
}
void SapXepE()
{
	for(int i=0; i<nE -1; i++)
		for(int j=i+1; j<nE; j++)
			if(wE[i]>wE[j]
			{
				Swap(wE[i], wE[j]);
				Swap(E1[i], E1[j]);
				Swap(E2[i], E2[j]);
			}
}
void Kruskal()
{
	for(int =0; i<nE; i++)
	{
		if(Tontai(E1[i], T1, nT) == 1 && Tontai(E2[i], T2, nT)==1)
			continue;
		if(Tontai(E2[i], T2, nT) == 1 && Tontai(E2[i], T1, nT)==1)
			continue;
		T1[nT]= E1[i];
		T2[nT]=E2[i];
		wT[nT]=wE[i];
		nT++;
		if(nT == n-1)
			break;
	}
}
void output(bool VertexName)
{
	int tong=0;
	for(int i=0; i<nT; i++)
	{
		if(VertexName)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ")= " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong+= wT[i];
	}
	cout << "\n Tong = " << tong;
}
void outputE(bool VertexName)
{
	int tong =0;
	for(int i=0; i<nE; i++)
	{
		if(VertexName)
			cout << endl << "(" << vertex[E1[i]] << "," << vertex[E2[i]] << ") = " << wE[i];
		else
			cout << endl << "(" << E1[i] << "," << E2[i] << ") = " << wE[i];
		tong += wE[i];
	}
	cout << "\n Tong = " << tong;
}
int ConnectedComponents()
{
	int visited[Max];
	in nV=0;
	int i=0, j=0;
	int nC=0;
	while(nV<n)
	{
		for(j=0; j<n; j++)
		{
			if(a[i][j] !=0 && visited[j]!=1)
			{
				visited[j]=1;
				nV++;
				i=j;
				break;
			}
		}
		if(j>=n&& i<n-1)
		{
			i++;
			visited[i]=1;
			nV++;
			nC++;
		}
		else if(j>n && i>=n-1)
		{
			i=1;
			visited[i]=1;
			nV++;
			nC++;
		}
	}
	return nC;

}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "------BAI TAP 5, CHUONG 6, TIM KIEM KHUNG TOI THIEU, KRUSKAL -----";
	cout << "1.Khoi tao ma tran ke rong" << endl;
	cout << "2.Nhap ma tran ke tu file text" << endl;
	cout << "3.Nhap ma tran ke" << endl;
	cout << "4.Xuat ma tran ke" << endl;
	cout << "5.Tim cay khung toi thieu bang KRSKAL " << endl;
	cout << "6.In ra tap E" << endl;
	cout << "7.Connected Graph - Do thi lien thong" << endl;
	cout << "Thoat" << endl;
	do{
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao ma tran ke thanh cong!\n";
			break;
		case 2: 
			inputGraphFromText();
			cout << "Ban vua nhap ma tran ke tu file: \n";
			outputGraph():
			break;
		case 3: 
			inputGraph();
			cout << "Ban vua nhap ma tran ke: \n";
			outputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			nT=0;
			TaoE();
			SapxepE();
			Kruskal();
			cout << "Cay khung toi thieu voi KRUSKAL: " << endl;
			output(true);
			break;
		case 6: 
			outputE(true);
			break;
		case 7:
			i=ConnectedComponents();
			cout << "Do thi co so tplt=" << i << endl;
			break;
		case 8: 
			cout << "Gud bye... !" << endl;
			break;
			default:
			break;
		}
	} while (choice !=8);
	system("pause");
	return 0;
}





	