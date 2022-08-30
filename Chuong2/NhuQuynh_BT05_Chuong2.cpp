#include<iostream>
#include<stdio.h>

using namespace std;

//Câu 10.1 - Khai báo cấu trúc stack
struct Node {
	int info;
	Node* link;
};
Node* sp;
//Câu 10.2 - Khởi tạo stack rỗng
void init() {
	sp = NULL;
}
//Câu 10.3 - Kiểm tra stack rỗng
int isEmpty() {
	if (sp == NULL)
		return 1;
	return 0;
}
//Câu 10.4 - Thêm phần tử vào đầu stack
int Push(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}
//Câu 10.5 - Lấy ra 1 phần tử đầu từ stack
int Pop(int& x) {
	if (!isEmpty()) 
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuất stack
void Process_stack() {
	if (sp != NULL)
	{
		Node* p = sp;
		do {
			cout << p->info << " <--";
			p = p->link;
		} while (p != NULL);
		cout << endl;
	}
	else cout << " Rong \n";
}
//Câu 10.6 - Chuyển đổi hệ thập phân sang hệ nhị phân
int Dec_Bin(int x)
{
	if (x >= 0)
	{
		cout << "So nhi phan cua " << x << " la: ";
		int du;
		do {
			du = x % 2;
			Push(du);
			x = x / 2;
		} while (x != 0);
		while (Pop(du) == 1)
		{
			cout << du;
		}
		cout << "\n";
		return 1;
	}
	return 0;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "=== Bai tap 10 - Chuong 2 - STACK voi DSLK ===\n";
	cout << "1. Khoi tao STACK rong\n";
	cout << "2. Them phan tu vao STACK\n";
	cout << "3. Lay phan tu ra khoi STACK\n";
	cout << "4. Kiem tra STACK co rong hay khong?\n";
	cout << "5. Xuat stack\n";
	cout << "6. Chuyển đổi hệ thập phân sang hệ nhị phân\n";
	cout << "7. Tháp Hà Nội\n";
	cout << "8. Thoat\n";

	do {
		cout << "\nVui long chon so: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao STACK thanh cong\n";
			break;
		case 2:
			cout << "Nhap phan tu can them x = ";
			cin >> x;
			i = Push(x);
			if (i == 1) {
				cout << "Them x = " << x << " vao STACK thanh cong!!\n";
				cout << "STACK sau khi them la: \n";
				Process_stack();
			}
			else
				cout << "Them khong thanh cong\n";
			break;
		case 3:
			i = Pop(x);
			if (i == 1) {
				cout << "Lay ra tu STACK thanh cong, gia tri lay ra la x = " << x << endl;
				cout << "STACK sau khi lay ra 1 phan tu la: \n";
				Process_stack();
			}
			else
				cout << "Lay khong thanh cong\n";
			break;
		case 4:
			i = isEmpty();
			if (i == 1)
				cout << "STACK dang rong\n";
			else
				cout << "STACK khong rong\n";
			break;
		case 5:
			Process_stack();
			break;
		case 6:
			cout << "Chuyen doi he thap phan sang he nhi phan\n";
			cout << "Moi nhap so thap phan duong: ";
			cin >> x;
			i = Dec_Bin(x);
			if (i == 0) cout << " Error \n";
			break;
		case 7:
			cout << "Thap Ha Noi\n";
			break;
		default:
			break;
		}
	} while (choice != 8);

	system("pause");
	return 0;
}