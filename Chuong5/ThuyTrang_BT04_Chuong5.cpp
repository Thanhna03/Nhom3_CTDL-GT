//Khuong Thanh Tam_2151050385_IT01
#include<iostream>
using namespace std;
constexpr auto MAX = 20;
int a[MAX][MAX];
int n;
int C[MAX];

int bfs[100];
int nbfs = 0;

int dfs[100];
int ndfs = 0;

//================================
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
//================================
void init()
{
	front = rear = NULL;
}
//================================
void initDuyet(int n)
{
	n = 0;
}
//4.1 Nhap ma tran ke 
void input()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//4.2 Xuat ma tran ke
void output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
//Push
int push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}
	return 1;
}
//Pop
int pop(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = p->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Khoi tao dinh chua xet
void ChuaXet()
{
	for (int i = 0; i < n; i++)
	{
		C[i] = 1;
	}
}
//4.3 Duyet do thi theo chieu rong (Queue_DSLKD)
void BFS(int v) // v la dinh bat dau
{
	int w, p;
	push(v);
	C[v] = 0;
	while (front != NULL)
	{
		pop(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				push(w);
				C[w] = 0;
			}
		}
	}
}
//Xuat BFS
void output_BFS()
{
	for (int i = 0; i < nbfs; i++)
	{
		cout << char(bfs[i] + 'A') << " ";
	}
}
//4.4 Duyet do thi theo chieu sau (Stack_DSLKD)
void DFS(int s) // s la dinh bat dau
{
	push(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (front != NULL)
	{
		if (v == n)
			pop(u);
		for (v = 0; v < n; v++)
		{
			if (a[u][v] != 0 && C[v] == 1)
			{
				push(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}
// Xuat DFS
void output_DFS()
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << char(dfs[i] + 'A') << " ";
	}
}
//4.5 Duyet X co ton tai tren do thi
void search(int x, int v)
{
	int w, p;
	push(v);
	C[v] = 0;
	while (front != NULL)
	{
		pop(p);
		if (x == p)
		{
			cout << "Ton tai\n";
			return;
		}
		for (w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				push(w);
				C[w] = 0;
			}
		}
		cout << "Khong ton tai\n";
	}
}
int main()
{
	init();
	int chon;
	system("cls");
	cout << "===========BAI TAP 4 _ CHUONG 5==========" << endl;
	cout << "1.Nhap ma tran ke cua do thi 5.1" << endl;
	cout << "2.Xuat ma tran ke cua do thi 5.1" << endl;
	cout << "3.Duyet do thi theo chieu rong (theo Queue bang DSLKD)" << endl;
	cout << "4.Duyet do thi theo chieu sau (theo Stack bang DSLKD)" << endl;
	cout << "5.Kiem tra X co ton tai hay khong" << endl;
	cout << "6.Thoat" << endl;
	do
	{
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			input();
			break;
		case 2:
			cout << "\nDo thi duoc bieu dien duoi dang ma tran ke\n";
			output();
			break;
		case 3:
			cout << "\nKet qua duyet theo BFS (voi dinh xuat phat la A): \n";
			init();
			ChuaXet();
			BFS(0);
			output_BFS();
			break;
		case 4:
			cout << "\nKet qua duyet theo DFS (voi dinh xuat phat la A): \n";
			init();
			ChuaXet();
			DFS(0);
			output_DFS();
			break;
		case 5:
			int x;
			cout << "Nhap dinh can tiem: ";
			cin >> x;
			search(x, 0);
			break;
		}
	} while (chon != 6);
	system("pause");
	return 0;
}