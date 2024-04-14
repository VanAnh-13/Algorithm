#include <bits/stdc++.h>
#define MAX 6

using namespace std;

struct HangHoa
{
    char maHang[50];
    char tenHang[70];
    char DVtinh[50];
    int donGia;
    int soLuong;
    int thanhTien;

    void inputHangHoa()
    {
        cout << "\tNhap ma hang: ";
        cin.getline(maHang, sizeof(maHang) - 1);
		     
		cout << "\tNhap ten hang: ";
        cin.getline(tenHang, sizeof(tenHang) - 1);

        cout << "\tNhap don vi tinh: ";
        cin.getline(DVtinh, sizeof(DVtinh) - 1);

        cout << "\tNhap don gia: ";
        cin >> donGia;
        cin.ignore();

        cout << "\tNhap so luong: ";
        cin >> soLuong;
        cin.ignore();
        
        thanhTien = donGia * soLuong;
    }                  
};

struct List
{
    int count;
    HangHoa id[MAX];
};

void Inittialize(List &L)
{
    L.count = -1;
}

bool Full(List L)
{
    return L.count == MAX - 1;
}

bool isEmply(List L)
{
    return L.count == -1;
}

void Add(List &L, HangHoa hangHoa)
{
    if (Full(L))
        return;

    else
    {
        L.count++;
        L.id[L.count] = hangHoa;
    }
}

void InputList(List &L)
{
    Inittialize(L);
    HangHoa hangHoa;

    int i = 0;

    while (true)
    {
        cout << "Nhap mat hang thu " << ++i << " : \n";
        hangHoa.inputHangHoa();
        Add(L, hangHoa);

        if (i == MAX)
            return;
    }
}

void OutputList(List L)
{ 
    printf("%sSTT%-10sMa hang%-10sTen Hang%-10sDV tinh%-10sDon Gia%-10sSo luong%-10sThanh tien \n", "", " ", " ", " ", " ", " ", " ");

    for (int i = 0; i <= L.count; i++)
    {
        printf("%-14d%-17s%-18s%-17s%-17d%-17d %d \n",
               i + 1, L.id[i].maHang, L.id[i].tenHang, L.id[i].DVtinh, L.id[i].donGia, L.id[i].soLuong, L.id[i].thanhTien);
    }
}

void EarseGoods(List &L)
{
	for(int v = 3; v <= L.count; v++)
		L.id[v - 1] = L.id[v];
		
	L.count--;
		
	cout << "Danh sach sau khi xoa phan tu dau tien la: \n";
	OutputList(L);
}

void AddGoods(List &L)
{
	HangHoa goods;
	cout << "Nhap thong tin hang hoa muon them: \n";
	goods.inputHangHoa();
	
	for(int v = L.count; v >= 0; v--)
		L.id[v + 1] = L.id[v];
		
	L.id[0] = goods;
	L.count++;
	 
	cout << "Danh sach sau khi them phan tu dau tien la: \n";
	OutputList(L);
}

void SortIntoMoney(List &L)
{
	for(int i = 0; i < L.count - 1; i++)
	{
		for(int j = L.count; j > i; j--)
		{
			if(L.id[j - 1].thanhTien < L.id[j].thanhTien)
			{
				HangHoa tam = L.id[j - 1];
				L.id[j - 1] = L.id[j];
				L.id[j] = tam;
			}
		}
	}
		
	cout << "Danh sach sau khi sap xep theo chieu giam dan cua thanh tien la: \n";
	OutputList(L);	
}

int main()
{
    List L;
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    InputList(L);
    
	cout << "----------------------------------------------------------------------------------------------------------------\n";
    OutputList(L);
    
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    EarseGoods(L);
    
    cout << "----------------------------------------------------------------------------------------------------------------\n";
	AddGoods(L);    
  
    cout << "----------------------------------------------------------------------------------------------------------------\n";
	SortIntoMoney(L);
	
    return 0;
}
