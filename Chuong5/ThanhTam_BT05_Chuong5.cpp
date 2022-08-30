//Khương Thanh Tâm_2151050385_IT01
//BT 05_Chương 5: Đồ thị hình 5.1

#include<iostream>
using namespace std;
#define MAX 20


int C[MAX]; 
int bfs[100];
int nbfs = 0; 
int dfs[100];
int ndfs = 0;

//=============================================
struct Node
{
    int info;
    Node* link;
};
Node* first[MAX]; 
int n; 

Node* front, * rear;
Node* sp; 
//=============================================
void initDSK()
{
    for (int i = 0;i < n;i++)
        first[i] = NULL;
}
//=============================================
void insert_first(Node*& f, int x)
{
    Node* p;
    p = new Node;
    p->info = x;
    p->link = f;
    f = p;
}
//=============================================
void input_MaTranKe()
{
    int a[MAX][MAX] = { 
    {0,1,1,1,0,0,0},
    {1,0,1,0,1,1,0},
    {1,1,0,1,0,1,0},
    {1,0,1,0,0,1,1},
    {0,1,0,0,0,1,0},
    {0,1,1,1,1,0,1},
    {0,0,0,1,0,1,0}
    };
    int na = 7; 

    n = na;
    for (int i = 0;i < n;i++)
    {
        insert_first(first[i], i);

        for (int j = 0;j < n;j++)
        {
            if (a[i][j] != 0)
                insert_first(first[i], j);
        }
    }
}
//5.1 Nhap danh sach ke
void input()
{
    int d, x, m;
    cout << "nhap so dinh do thi n: ";
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cout << "\nnhap dinh thu " << i + 1 << " : ";
        cin >> d;
        insert_first(first[i], d);

        cout << "nhap vao so dinh ke cua " << d << " : ";
        cin >> m;
        for (int j = 0;j < m;j++)
        {
            cin >> x;
            insert_first(first[i], x);
        }
    }
}

//=============================================
void output_list(Node* f)
{
    if (f != NULL)
    {
        Node* p = f;
        while (p != NULL)
        {
            cout << char(p->info + 'A') << " ";
            p = p->link;
        }
    }
}
//5.2 Xuat danh sach ke
void output()
{
    if (n > 0)
        for (int i = 0;i < n;i++)
        {
            cout << endl << "Danh sach thu " << i + 1 << ": ";
            output_list(first[i]);
        }
    else
        cout << "rong";
}

//=============================================
void initQ()
{
    front = rear = NULL;
}
//=============================================
int isEmptyQ()
{
    if (front == NULL)
        return 1;
    return 0;
}
//=============================================
int PushQ(int x)
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
//=============================================
int PopQ(int& x)
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
//5.3 Duyet BFS dua tren Queue voi DSLKD
void BFS(int v) // v là đỉnh bắt đầu
{
    int p;

    PushQ(v);
    C[v] = 0;
    while (front != NULL)
    {
        PopQ(p);
        bfs[nbfs] = p;
        nbfs++;

        for (Node* w = first[p]; w != NULL; w = w->link)
            if (C[w->info] == 1) //a[p][w]
            {
                PushQ(w->info);
                C[w->info] = 0;
            }
    }
}
//=============================================
void khoitaochuaxet()
{
    for (int i = 0; i < n; i++) // n là số đỉnh của đồ thị
        C[i] = 1;
}
//=============================================
void output_bfs()
{
    for (int i = 0; i < nbfs; i++) // n là số đỉnh của đồ thị
        cout << char(bfs[i] + 'A') << "  ";
}


//=============================================
void initS()
{
    sp = NULL;
}
//=============================================
int isEmptyS()
{
    if (sp == NULL)
        return 1;
    return 0;
}
//=============================================
int PushS(int x)
{
    Node* p = new Node;
    p->info = x;
    p->link = sp;
    sp = p;
    return 1;
}
//=============================================
int PopS(int& x)
{

    if (sp != NULL) // if(!isEmpty())
    {
        Node* p = sp;
        x = p->info;
        sp = p->link;
        delete p;
        return 1;
    }
    return 0;
}
//5.4 Duyet DFS dua tren Stack voi DSLKD
void DFS(int s) 
{
    Node* vN=NULL;
    PushS(s);
    dfs[ndfs] = s;
    ndfs++;
    C[s] = 0;
    int u = s, v = -1;
    while (sp != NULL)
    {
        if (vN == NULL)
            PopS(u);
        for ( vN = first[u]; vN != NULL; vN = vN->link) //vN: dinh v Node
        {
            v = vN->info;
            if (C[v] == 1) //a[u][v] != 0
            {
                PushS(v);
                dfs[ndfs] = v;
                ndfs++;
                C[v] = 0;
                u = v;
                break;
            }
        }
    }
}
//=============================================
void output_dfs()
{
    for (int i = 0; i < ndfs; i++)
    {
        cout << char(dfs[i] + 'A') << " ";
    }
}
//=============================================
void search(int x, int v)
{
    int w, p;
    PushQ(v);
    C[v] = 0;
    while (front != NULL)
    {
        PopQ(p);
        if (x == p)
        {
            cout << "Ton tai\n";
            return;
        }
        for (w = 0; w < n; w++)
        {
            if (C[w] && a[p][w] == 1)
            {
                PushQ(w);
                C[w] = 0;
            }
        }
        cout << "Khong ton tai\n";
    }
//=============================================
int main()
{
    int Vstart = 0;//dinh bat dau
    int chon;
    system("cls");
    cout << "===========BAI TAP 5 _ CHUONG 5==========" << endl;
    cout << "1.Nhap danh sach ke cua do thi 5.1" << endl;
    cout << "2.Xuat danh sach ke cua do thi 5.1" << endl;
    cout << "3.Duyet do thi theo chieu rong (theo Queue bang DSLKD)" << endl;
    cout << "4.Duyet do thi theo chieu sau (theo Stack bang DSLKD)" << endl;
    cout << "5.Kiem tra X co ton tai hay khong" << "\n\n";
    cout << "0.Thoat" << endl;
    do
    {
        cout << "\nMoi ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            input();
            /*initDSK();
            input_MaTranKe();*/
            break;
        case 2:
            cout << "\nDo thi duoc bieu dien duoi dang danh sach ke\n";
            output();
            break;
        case 3:
            cout << "\nKet qua duyet theo BFS (voi dinh xuat phat la " << Vstart << " ): \n";
            initQ();
            khoitaochuaxet();
            BFS(Vstart);
            output_bfs();
            break;
        case 4:
            cout << "\nKet qua duyet theo DFS (voi dinh xuat phat la " << Vstart << " ): \n";
            initS();
            khoitaochuaxet();
            DFS(Vstart);
            output_dfs();
            break;
        case 5:
            int x;
            cout << "Nhap dinh can tiem: ";
            cin >> x;
            search(x, 0);
            break;
        default: chon = 0;
        }
    } while (chon != 0);
    system("pause");
    return 0;
}

