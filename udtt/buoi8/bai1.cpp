#include <bits\stdc++.h>

using namespace std;

struct Fan
{
    string name_manufacture;
    string color;
    int price;
};

struct FanBuy
{
    int fanCanBuy;
    Fan *fanBuy;

    void output()
    {
        cout << fanCanBuy << " " << fanBuy->name_manufacture
             << " " << fanBuy->color << " " << fanBuy->price;
    }
};

bool fan_can_buy(Fan *fan_have, int price_have, int sum_of_fan, vector<FanBuy> &fan_buy)
{
    int i = 0;

    while (i < sum_of_fan and price_have)
    {
        fan_buy.push_back({price_have / fan_have[i].price, &fan_have[i]});
        price_have %= fan_have[i].price;
        i++;
    }

    return i != 0;
}

int main(int argc, char const *argv[])
{
    Fan fan_have[] = {
        {"Samsung", "Vang", 20000},
        {"Sony", "Trang", 500000},
        {"LG", "Den", 89000},
        {"Hyundai", "Cam", 30000},
        {"Tesla", "Nau", 700000},
    };
    int sum_of_fan = sizeof(fan_have) / sizeof(fan_have[0]);
    int price_have = 20000;
    vector<FanBuy> fan_buy;

    if (fan_can_buy(fan_have, price_have, sum_of_fan, fan_buy))
        for (int i = 0; i < fan_buy.size(); i++)
            fan_buy[i].output();

    else
        cout << "khong co quat thoa man !" << endl;

    return 0;
}
