#include <iostream>
#include <algorithm>

using namespace std;

bool cointChoose(int *money, int sumOfMoney, long moneyNeed, int *resultChoose)
{
    int i = 0;

    while (i < sumOfMoney && moneyNeed > 0)
    {
        resultChoose[i] = moneyNeed / money[i];
        moneyNeed %= money[i];
        i++;
    }

    if (moneyNeed > 0)
        return false;
    else
        return true;
}

int main()
{
    int sumOfMoney;
    cout << "Enter sum of money you have: ";
    cin >> sumOfMoney;

    int *money = new int[sumOfMoney];

    for (int i = 0; i < sumOfMoney; i++)
    {
        cout << "money[" << i + 1 << "]: ";
        cin >> money[i];
    }

    int moneyNeed;
    cout << "Enter noney you want to check: ";
    cin >> moneyNeed;

    int *result = new int[sumOfMoney]{0};

    if (cointChoose(money, sumOfMoney, moneyNeed, result))

        for (int i = 0; i < sumOfMoney; i++)
            cout << result[i] << " ";

    else
        cout << "Your money you input can't have result";
}