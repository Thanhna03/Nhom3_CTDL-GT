#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int n;
//======================================
void output()
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<"\t";
	}
}
//======================================

//======================================

//======================================

//======================================

//======================================

//======================================
int main()
{
	int chon;
	system("cls");
	cout << "=========BT02_CHUONG 2===========" << endl;
	cout << "2.1 Khai bao cau truc danh sach" << endl;
	cout << "2.2 Them mot phan tu vao danh sach" << endl;
	cout << "2.3 Xuat cac phan tu trong danh sach" << endl;
	cout << "2.4 Tim mot phan tu trong danh sach(bang phuong phap tim kiem tuan tu)" << endl;
	cout << "2.5 Tim mot phan tu trong danh sach(bang phuong phap tim kiem nhi phan)" << endl;
	cout << "2.6 Tim mot phan tu. Neu tim thay, xoa phan tu nay" << endl<<endl;

	cout << "0.Thoat" << endl;
	do
	{
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout<<"Khai bao cau truc danh sach thanh cong! "<<endl;
			break;
		case 2:
			
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
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");
	return 0;
}
