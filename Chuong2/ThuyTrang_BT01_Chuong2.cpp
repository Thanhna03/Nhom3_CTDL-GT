#include<iostream>
using namespace std;
//1.1 Khai bao cau truc danh sach
#define MAX 100
int a[MAX];
int n;
//1.2 Viet thu tuc nhap danh sach
void input()
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap a[" << i << "]: ";
		cin >> a[i];
	}
}
//1.3 Viet ham xuat danh sach
void output()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
//1.4 Viet ham tim mot phan tu trong danh sach
int search(int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}
//1.5 Them mot phan tu vao cuoi danh sach
void insert_last(int x)
{ 
	a[0] = x;
	n++;
}
//1.6 Xoa phan tu cuoi danh sach va xoa tai i
int Del(int x)
{
	if (x >= 0 && x < n)
	{
		for (int j = x; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
//===================================
int main()
{
	int chon,x;
	system("cls");
	cout << "==========BT01_CHUONG 2==========" << endl;
	cout << "1.1 Khai bao cau truc danah sach" << endl;
	cout << "1.2 Viet danh sach" << endl;
	cout << "1.3 Xuat danh sach " << endl;
	cout << "1.4 Tim mot phan tu trong danh sach" << endl;
	cout << "1.5 Them mot phan tu vao cuoi danh sach" << endl;
	cout << "1.6 Xoa phan tu cuoi danh sach" << endl;
	cout << "1.7 Xoa phan tu tai vi tri i" << endl;
	cout << "1.8 Tim mot phan tu trong danh sach. Neu tim thay thi xoa" << endl;

	cout << "0.Thoat" << endl;
	do
	{
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "\nKhai bao cau truc danh sach thanh cong\n";
			break;
		case 2:
			input();
			break;
		case 3:
			cout << "Mang ban dau" << endl;
			output();
			break;
		case 4:
			cout << "Nhap so can tim: ";
			cin >> x;
			int k = search(x);
			if (k == -1) cout << "Khong ton tai" << endl;
			else cout << "Ton tai" << endl;
			break;
		 case 5:
			cout << "Phan tu muon them vao danh sach: ";
			cin >> x;
			insert_last(x);
			cout << "Mang sau khi them " << x << "la: " << endl;
			output();
			break;
		case 6:
			cout << "Mang sau khi xoa phan tu cuoi: " << endl;
			Del(n);
			output();
			break;  
		case 7:
			cout << "Nhap vi tri can xoa: ";
			cin >> x;
			Del(x);
			cout << "Mang sau khi xoa tai " << x << "la: ";
			output();
			break;
		case 8: 

			break;
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");

	return 0;
}