//#include <iostream>
//#include <cstdlib>
//using namespace std;
//const int M=100;
//void HoanVi(int &a, int &b)
//{
//	int temp;
//	{
//		temp = a;
//		a = b;
//		b = temp;
//	}
//
//}
//void XepTang(int a[], int n)
//{
//	for(int i=0; i<n-1; i++)
//		for (int j=i+1; j<n; j++)
//			if(a[i]<a[j])
//				HoanVi(a[i], a[j]);
//	return;
//}
//void XepGiam(int a[], int n)
//{
//	for(int i=0; i<n-1; i++)
//		for (int j=i+1; j<n; j++)
//			if(a[i]<a[j])
//				HoanVi(a[i], a[j]);
//	return;
//}
//void Xuat(int a[], int n)
//{
//	for(int i=0; i<n; i++)
//		cout << " " << a[i];
//}
//int main()
//{
//	int a[M], n;
//	cout << " Nhap so phan tu cua mang: ";
//	cin >> n;
//	cout << " Xuat mang: " << endl;
//	for (int i=0; i<n; i++)
//	{
//		a[i] = rand()%20;
//		cout << " " << a[i];
//	}
//	cout << "\nMang xep tang: " << endl;
//	XepTang(a,n);
//	Xuat(a, n);
//	cout << "\nMang xep giam: " << endl;
//	XepGiam(a,n);
//	Xuat(a, n);
//	cout << endl;
//	system ("pause");
//	return 0;
//}