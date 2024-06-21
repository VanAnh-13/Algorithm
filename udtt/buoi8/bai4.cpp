#include <bits\stdc++.h>

using namespace std;

struct Mobile
{
    string label;
    int size;
    int cost;
};

int **table_result(int length, int total, Mobile *mobile)
{
    int **result = new int *[total + 1];

    for (int i = 0; i <= total; i++)
        result[i] = new int[length + 1];

    for (int i = 0; i <= length; i++)
        result[0][i] = 0;

    for (int i = 1; i <= total; i++)
        for (int j = 0; j <= length; j++)
        {
            result[i][j] = result[i - 1][j];

            if (mobile[i].size <= j)
            {
                int tmp = result[i][j - mobile[i].size] + mobile[i].cost;

                if (tmp > result[i][j])
                {
                    result[i][j] = tmp;
                }
            }
        }

    return result;
}

vector<Mobile> result_get(int length, int total, Mobile *mobile)
{
    int i = total, j = length;
    vector<Mobile> result;
    int **table = table_result(length, total, mobile);

    while (i != 0)
    {
        if (table[i][j] != table[i - 1][j])
        {
            result.push_back(mobile[i]);
            j -= mobile[i].size;
        }

        i--;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    Mobile mobile_have[] = {
        {"LG", 80, 1000000},
        {"Sony", 100, 500000},
        {"Samsung", 500, 2000000},
        {"Xiaomi", 500, 3000000},
        {"Iphone", 600, 7000000},
    };

    int total = sizeof(mobile_have) / sizeof(mobile_have[0]);
    int length = 1000;
    vector<Mobile> result = result_get(length, total, mobile_have);

    for (int i = 0; i < result.size(); i++)
        cout << result[i].label << " " << result[i].cost << endl;

    return 0;
}
