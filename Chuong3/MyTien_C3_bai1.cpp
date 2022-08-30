#include<stdio.h>
#include<iostream>
#include<ctime>
#define max 100
using namespace std;
//1.1 khai bao
int a[max];
int n;
//1.2 nhap danh sach
void input(int a[], int n)
{
	cout << "Nhap so luong phan tu danh sach: ";
	cin >> n;
	cout << "Nhap cac phan tu cua danh sach: "<< endl;
	for(int i=0; i<n; i++)
	{
		cout << "a["<<i<<"]";
		cin >> a[i];
	}
}
//1.3 xuat danh sach
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//Nhap danh sach tu dong
void init(int a[], int n)
{
	cout << "Nhap so luong phan tu danh scah: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		a[i]=rand()%1000+1;
	}
	cout << "Danh sach them vao ngau nhien la: "<< endl;
	for(int i=0; i<n; i++)
	{
		cout << a[i] << " ";
	}
}
//coppy array
void coppy_array(int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
	{
		b[i]=a[i];
	}
}
//1.4
void insertion_sort(int a[], int n)
{
	int i, key, j;
	for(i=1; i<n; i++)
	{
		key=a[i];
		j=i+1;
		while(0<=j && key<a[i])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=key;
	}
}
//swap
void swap(int &a , int &b)
{
	int t=a;
	a=b;
	b=t;
}
//1.5
void selection_sort(int a[], int n)
{
	int min_pos, i, j;
	for(i=0; i<n-1;i++)
	{
		min_pos=i;
		for(j=i+1; j<n; j++)
			if(a[j]<a[min_pos])
			{
				min_pos=j;
			}
		swap(a[min_pos], a[i]);
	}
}
//1.6
void interchange_sort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				swap(a[i], a[j]);
}
//1.7
void bubble_sort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=n-1; j>i; j--)
			if(a[j-1] > a[j])
				swap(a[j-1], a[j]);
}
//1.8
void quick_sort(int a[], int l, int r)
{
	int x=a[(l+r)/2];
	int i=l;
	int j=r;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while (a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(l<j)
		quick_sort(a, l, j);
	if(i<r)
		quick_sort(a, i, r);
}
//1.9
void shift(int a[], int i, int n)
{
	int j= 2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x= a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a, j, n);
	}
}
void heap_sort(int a[], int n)
{
	int i=(n/2)-1;
	while(i>=0)
	{
		shift(a, i, n);
		i--;
	}
	int r=n-1;
	while(r>0)
	{
		swap(a[0], a[r]);
		r--;
		if(r>0)
			shift(a, 0, r);
	}
}
//1.10
void searchSequence(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] !=x){
		i++;
	}
	if(i==n){
		cout << "khong tim thay";
	}
	else
	{
		cout << "Tim thay vi tri tai " << i;
	}
}
//1.11
int searchBinary(int a[], int l, int r, int x)
{
	if(r>=l){
		int mid=l+(r-l)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid]>x)
			return searchBinary(a,l, mid-1, x);
		return searchBinary(a, mid+1, r, x);
	}
	return -1;
}

int main()
{
	int b[max];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "------menu------"
		<< "0.Khoi tao danh sach ngau nhien\n"
		<< "1.Nhap danh sach tu ban phim\n"
		<< "2.Xuat danh sach\n"
		<< "3.Xep thu tu selection_sort\n"
		<< "4.Xep thu tu insertion_sort\n"
		<< "5.bubble_sort\n"
		<< "6.interchange_sort\n"
		<< "7.quick_sort\n"
		<< "8.heap_sort\n"
		<< "9.Tim kiem phan tu trong danh sach co thu tu(tuan tu)\n"
		<< "10.Tim kiem phan tu trong danh sach co thu tu(nhi phan)\n"
		<< "11.Thoat" << endl;
	do{
		cout << "\nVui long chon de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			
				init(a, n);
				break;
			
		case 1:
			
				input(a,n);
				break;
			
		case 2:
			
				cout << "DS dang co la: " << endl;
				output(a,n);
				break;
			
		case 3:
			
				coppy_array(a, b, n);
				start = clock();
				selection_sort(b,n);
				duration=(clock()-start)/(double)CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << "Ds sau khi xep xong voi selection_sort la" << endl;
					output(b,n);
				}
				if(duration>0)
				{
					cout << "Thoi gian selection_sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
				break;
			
		case 4:
			
				coppy_array(a, b, n);
				start = clock();
				insertion_sort(b,n);
				duration=(clock()-start)/(double)CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << "Ds sau khi xep xong voi insertion_sort la" << endl;
					output(b,n);
				}
				if(duration>0)
				{
					cout << "Thoi gian insertion_sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
				break;
			
		case 5:
			
				coppy_array(a, b, n);
				start = clock();
				bubble_sort(b,n);
				duration=(clock()-start)/(double)CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << "Ds sau khi xep xong voi bubble_sort la" << endl;
					output(b,n);
				}
				if(duration>0)
				{
					cout << "Thoi gian bubble_sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
				break;
			
		case 6:
			
				coppy_array(a, b, n);
				start = clock();
				interchange_sort(b,n);
				duration=(clock()-start)/(double)CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << "Ds sau khi xep xong voi interchange_sort la" << endl;
					output(b,n);
				}
				if(duration>0)
				{
					cout << "Thoi gian interchange_sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
				break;
			
		case 7:
			
				coppy_array(a, b, n);
				start = clock();
				quick_sort(b, 0, n-1);
				duration=(clock()-start)/(double)CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << "Ds sau khi xep xong voi quick_sort la" << endl;
					output(b,n);
				}
				if(duration>0)
				{
					cout << "Thoi gian quick_sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
				break;
			
		case 8:
			
				coppy_array(a, b, n);
				start = clock();
				heap_sort(b,n);
				duration=(clock()-start)/(double)CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << "Ds sau khi xep xong voi heap_sort la" << endl;
					output(b,n);
				}
				if(duration>0)
				{
					cout << "Thoi gian heap_sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
				break;
		case 9:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(duration>0)
				cout << "\n-Thoi gian tim kiem tuan tu la: " << duration*1000000 << "Microseconds" << endl;
			break;
		case 10:
			cout << "Vui long nhp gia tri x= ";
			cin >> x;
			start = clock();
			i= searchBinary(b, 0, n, x);
			duration = clock() - start)/(double)CLOCKS_PER_SEC;
			if(i==-1)
				cout << "Khong tim thay x= " << x << " trong day " << endl;
			else
				cout << "Tim thay x=" << x << " tai vi tri i= " << i << endl;
			if(duration>0)
				cout << "\nThoi gian tim kiem nhi phan la: " << duration *10000000 << "Microseconds" << endl;
			break;
		case 11:
			    cout << "gud bye" << endl;
				break;
		default:
			break;
			}
				}while(choice!=11);
				system("pause");
				return 0;
}