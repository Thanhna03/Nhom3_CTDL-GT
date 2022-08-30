//#include <iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//const int M=100;
//int main()
//{
//	int a[M], n;
//	cout << " Nhap kich thuoc mang n = ";
//	cin >> n;
//	for(int i=2; i<=n; i++)
//	{
//		a[i] = i;
//		cout << setw(3) << a[i];
//	}
//	cout << endl;
//	for(int i=2; i<=sqrt((double)n); i++)
//	{
//		if(a[i])
//			for(int j = i*i; j<=n; j++)
//				if (j % i == 0)
//					a[j] = 0;
//		for (int k=2; k<=n; k++)
//			if(a[k]!=0)
//				cout << setw(3) << a[k];
//			else
//				cout << setw(3) << " ";
//		cout << endl;
//	}
//	system ("pause");
//	return 0;
//}