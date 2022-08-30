//#include <iostream>
//#include <cstdlib>;
//using namespace std;
//void XoaTrung(int a[], int &size)
//{
//	for (int i=0; i<size-1; i++)
//		for (int j=i+1; j<size; j++)
//		{
//			if(a[i] == a[j])
//			{
//				for(int k=j; k<size-1; k++)
//					a[k] = a[k+1];
//				size--;
//				j--;
//			}
//		}
//		return;
//}
//int main()
//{
//	const int M=100;
//	int a[M], n;
//	cout << " Nhap kich thuoc mang n = ";
//	cin >> n;
//	cout << " Mang a: \n";
//	for (int i=0; i<n; i++)
//	{
//		a[i] = rand()%10+1;
//		cout << " " << a[i];
//	}
//	XoaTrung(a, n);
//	cout << "\nMan sau khi xoa trung: \n";
//	for(int i=0; i<n; i++)
//		cout << " " << a[i];
//	cout << endl;
//	system("pause");
//	return 0;
//}