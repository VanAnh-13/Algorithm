#include <bits/stdc++.h>

using namespace std;

struct Fan
{
    string nameManufacture;
    string color;
    int cost;
};

struct FanBuy
{
    Fan *fan;
    int total_fan;
};

bool fanCanSell(int sumOfFan, Fan *fan, int price, vector<FanBuy> fan_sell)
{
    int i = 0;

    while (i < sumOfFan and price and fan[i].cost < price)
    {
        fan_sell.push_back({&fan[i], price / fan[i].cost});
        price %= fan[i].cost;
    }

    return fan_sell.size() != 0;
}
