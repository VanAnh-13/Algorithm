#include <bits\stdc++.h>

using namespace std;

struct Fan
{
    string nameManufacture;
    string fanColor;
    int price;
};

struct FanBuy
{
    int total;
    Fan *fan;
};

bool fanCanBuy(int price, int total, Fan *fan, vector<FanBuy> &fanBuy)
{
    int i = 0;

    while (i < total and price and fan[i].price < price)
    {
        cout << price << endl;
        fanBuy.push_back({price / fan[i].price, &fan[i]});
        price %= fan[i].price;
    }

    return fanBuy.size() != 0;
}

int main(int argc, char const *argv[])
{
    Fan fan[] = {
        {"Samsung", "Vang", 10000},
        {"LG", "Cam", 20000},
        {"Sony", "Den", 500000},
        {"Dien co 91", "Xanh", 500000},
        {"Xiaomi", "Trang", 60000},
        {"Huawei", "Do", 70000}};
    int sumOfFan = sizeof(fan) / sizeof(fan[0]);
    int price = 80;
    vector<FanBuy> fan_buy;

    if (fanCanBuy(price, sumOfFan, fan, fan_buy))
        for (int i = 0; i < fan_buy.size(); i++)
            cout << fan_buy[i].total << " " << fan_buy[i].fan->nameManufacture
                 << " " << fan_buy[i].fan->price << endl;
    else
        cout << "Khong co gia tri thoa man." << endl;
        
    return 0;
}
