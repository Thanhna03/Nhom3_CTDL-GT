//#include <iostream>
//#include <cstdlib>
//const int MAX = 100;
//using namespace std;
//void Nhap(int a[], int size);
//void Xuat(int a[], int size);
//bool Tim(int a[], int size, int x);
//void HoanVi(int &a, int &b);
//void DaoNguoc(int a[], int size);
//void Xoa(int a[], int &size, int p);
//int main()
//{
//	int a[MAX], n, x, p;
//	cout << "Nhap so phan tu mang: ";
//	cin >> n;
//	Nhap (a, n);
//	cout << "\nXuat mang: \n";
//	Xuat(a, n);
//	cout << "\nNhap gia tri x can tim: = ";
//	cin >> x;
//	if(Tim(a, n, x))
//		cout << " Tim thay " << x;
//	else
//		cout << " Khong tim thay " << x;
//	cout << "\nMang dao nguoc: \n";
//	DaoNguoc(a, n);
//	cout << "\nNhap vi tri p can xoa phan tu mang: ";
//	cin >> p;
//	Xoa(a, n, p);
//	cout << "\nMang da xoa: \n";
//	Xuat(a, n);
//	cout << endl;
//	system ("pause");
//	return 0;
//}
//void Nhap(int a[], int size)
//{
//	for(int i=0; i<size; i++)
//		a[i] = rand()%10;
//}
//void Xuat(int a[], int size)
//{
//	for(int i=0; i<size; i++)
//	{
//		cout << a[i];
//		if(i<size-1)
//			cout << ", ";
//	}
//	return;
//}
//bool Tim(int a[], int size, int x)
//{
//	int i=0;
//	bool kq = false;
//	while(i<size && a[i]!=x)
//		i++;
//	if(i<size)
//		kq =  true;
//	return kq;
//}
//void HoanVi(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void DaoNguoc(int a[], int size)
//{
//	int l = 0, r = size-1;
//	while(1<r)
//	{
//		HoanVi(a[l], a[r]);
//		l++;
//		r--;
//	}
//	return;
//}
//void Xoa(int a[], int &size, int p)
//{
//	for(int i=p; i<size-1; i++)
//		a[i] = a[i+1];
//	size--;
//	return;
//}