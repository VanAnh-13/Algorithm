#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    char maSinhVien[50];
    char hoVaTenDem[20];
    char ten[10];
    int namSinh;
    float diemTongKet;

    void InputSinhVien()
    {
        printf("%-10sMa Sinh Vien: ", " ");
        fflush(stdin);
        cin.getline(maSinhVien, sizeof(maSinhVien));
        
        if (strcmp(maSinhVien, "***") == 0)
            return;

        printf("%-10sHo Va Ten Dem: ", " ");
        fflush(stdin);
        cin.getline(hoVaTenDem, sizeof(hoVaTenDem));

        printf("%-10sTen: ", " ");
        fflush(stdin);
        cin.getline(ten, sizeof(ten));

        printf("%-10sNam Sinh: ", " ");
        cin >> namSinh;

        printf("%-10sDiem Tong Ket: ", " ");
        cin >> diemTongKet;
    }

    void OutputSinhVien()
    {
        printf("%-10sMa Sinh Vien: %s \n", " ", maSinhVien);
        printf("%-10sHo Va Ten Dem: %s\n", " ", hoVaTenDem);
        printf("%-10sTen: %s \n", " ", ten);
        printf("%-10sNam Sinh: %d \n", " ", namSinh);
        printf("%-10sDiem Tong Ket: %f \n", " ", diemTongKet);
    }
};

struct Node
{
    SinhVien infor;
    Node *next;
};

typedef Node *Tro;

void Inittialize(Tro &L)
{
    L = nullptr;
}

bool IsEmpty(Tro L)
{
    return L == nullptr;
}

void InputList(Tro &L)
{
    Tro F, E;
    Inittialize(L);

    int i = 1;

    do
    {
        cout << "Nhap thong tin sinh vien thu: " << i++ << ": \n";

        F = new Node;
        F->infor.InputSinhVien();
        F->next = nullptr;

        if (strcmp(F->infor.maSinhVien, "***") == 0)
            break;

        if (IsEmpty(L))
            L = F;

        else
            E->next = F;

        E = F;
    } while (1);
}

void OutputList(Tro L)
{
    Tro Q = L;

    if (IsEmpty(L))
        cout << "Danh Sach Rong !" << endl;

    int i = 0;

    while (Q != nullptr)
    {
        cout << "Thong tin sinh vien thu " << ++i << " : \n";
        Q->infor.OutputSinhVien();
        Q = Q->next;
    }
}

int LengList(Tro L)
{
    int i = 0;
    Tro Q = L;

    while (Q != nullptr)
    {
        i++;
        Q = Q->next;
    }

    return i;
}

void Earse(Tro &L)
{
    if (IsEmpty(L))
        cout << "Danh sah rong !";

    else
    {
        Tro Q = L;
        L = L->next;
        delete Q;
        cout << "Danh sach sau khi xoa phan tu dau tien la : \n";
        OutputList(L);
    }
}

Tro FindList(Tro L)
{
    Tro X = L;
    string maTimKiem = "sv8089";

    while (X != nullptr and X->infor.maSinhVien != maTimKiem)
        X = X->next;

    return X;
}

void XoaMaSinhVien(Tro &L)
{
    Tro W = FindList(L), Q = L;

    if (W == L)
        L = W->next;

    while (Q->next != W)
        Q = Q->next;

    Q->next = W->next;

    delete W;

    cout << "Mang sau khi xoa sinh vien co ma sv8089 la: " << endl;
    OutputList(L);
}

void ThemSinhVien(Tro &L)
{
    cout << "Nhap thong tin sinh vien can them: \n";

    Tro add = new Node;
    add->next = nullptr;
    add->infor.InputSinhVien();

    cout << "Nhap vi tri muon them : ";
    int viTri;
    cin >> viTri;

    Tro before = L;
    int i = 1;

    while (i < viTri - 1 and before->next != nullptr)
    {
        before = before->next;
        i++;
    }

    add->next = before->next;
    before->next = add;

    cout << "\nMang sau khi them phan tu la: " << endl;
    OutputList(L);
}

void LietKe(Tro L)
{
    Tro Q = L;
    string name = "Doanh";
    int i = 0;

    while (Q != nullptr)
    {
        if (Q->infor.ten == name)
        {
            cout << "Thong tin sinh vien co ten Doanh thu " << ++i << "la: \n";
            Q->infor.OutputSinhVien();
        }

        Q = Q->next;
    }
}

void SapXepDiem(Tro &L)
{
    Tro First, End, Middle;
    First = L;

    while (First->next != nullptr)
    {
        Middle = First;
        End = First->next;

        while (End != nullptr)
        {
            if (End->infor.diemTongKet > Middle->infor.diemTongKet)
                Middle = End;

            End = End->next;
        }

        if (Middle != First)
        {
            SinhVien tam = Middle->infor;
            Middle->infor = First->infor;
            First->infor = tam;
        }

        First = First->next;
    }

    cout << "Mang sau khi sap xep la: \n";
    OutputList(L);
}

void ThemSinhVienDaSapXep(Tro &L)
{
    Tro INFOR, LOOP;

    INFOR = new Node;
    LOOP = L;
    INFOR->next = nullptr;
    cout << "Nhap thong tin can them: \n";

    INFOR->infor.InputSinhVien();

    while (LOOP->next->infor.diemTongKet > INFOR->infor.diemTongKet)

        LOOP = LOOP->next;

    INFOR->next = LOOP->next;
    LOOP->next = INFOR;

    cout << "\nMang sau khi chen phan tu da sap xep la: " << endl;
    OutputList(L);
}

int main()
{
    Tro L;

    cout << "----------------------------------------------------------------------------\n";
    InputList(L);

    cout << "----------------------------------------------------------------------------\n";
    OutputList(L);

    cout << "----------------------------------------------------------------------------\n";
    cout << "Do dai cua mang la " << LengList(L) << endl;

    cout << "----------------------------------------------------------------------------\n";
    Earse(L);

    cout << "----------------------------------------------------------------------------\n";
    XoaMaSinhVien(L);

    cout << "----------------------------------------------------------------------------\n";
    ThemSinhVien(L);

    cout << "----------------------------------------------------------------------------\n";
    LietKe(L);

    cout << "----------------------------------------------------------------------------\n";
    SapXepDiem(L);

    cout << "----------------------------------------------------------------------------\n";
    ThemSinhVienDaSapXep(L);

    cout << "----------------------------------------------------------------------------\n";

    return 0;
}
