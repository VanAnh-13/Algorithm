#include <bits\stdc++.h>

using namespace std;

bool F1(int *money, int sumOfMoney, int moneyNeed, vector<int> &resultChoose)
{
    int i = 0;

    while (i < sumOfMoney and moneyNeed > 0)
    {
        resultChoose.push_back(moneyNeed / money[i]);
        moneyNeed %= money[i];
        i++;
    }

    return moneyNeed == 0;
}

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        cout << "money[" << i + 1 << "]: ";
        cin >> a[i];
    }

    int z;
    cin >> z;

    if (F1(a, n, z, result))
    {
        int sum = 0;

        for (int i = 0; i < result.size(); i++)
            if (result[i] != 0)
                sum += result[i];

        cout << sum << endl;
    }
    else
        cout << "Khong so cach chon !" << endl;
}