//#include <iostream>
//#include <cstdlib>
//using namespace std;
//void DEMPT(int a[], int& n)
//{
//	int dem;
//	for (int i = 0; i < n; i++)
//	{
//		dem = 1;
//		for (int j = i + 1; j < n - 1; j++)
//			if (a[i] == a[j])
//			{
//				dem++;
//				for (int k = j; k < n -1; k++)
//					a[k] = a[k + 1];
//				n--;
//				j--;
//			}
//		cout << a[i] << " so pt = " << dem << endl;
//	}
//}
//int main()
//{
//	const int M = 100;
//	int a[M], n, dem;
//	cout << " Nhap kich thuoc mang n = ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 99 + 1;
//		cout << " " << a[i];
//	}
//	cout << "\nCac phan tu: \n";
//	DEMPT(a, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << " " << a[i];
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}