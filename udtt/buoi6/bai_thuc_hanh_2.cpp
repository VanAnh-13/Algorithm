#include <bits\stdc++.h>

using namespace std;

struct Goods
{
    int value;
    int weight;
};

int **boxDynamic(int n, int m, Goods *goods)
{
    int **F = new int *[n];

    for (int i = 0; i <= n; i++)
        F[i] = new int[m];

    for (int j = 0; j <= m; j++)
        F[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            F[i][j] = F[i - 1][j];

            if (goods[i - 1].weight <= j)
            {
                int temporary = F[i][j - goods[i].weight] + goods[i - 1].value;

                if (temporary > F[i][j])
                    F[i][j] = temporary;
            }
        }
    }

    return F;
}

vector<int> result(int n, int m, Goods *goods)
{
    int i = n, j = m;
    vector<int> result_out;
    int **algorithm = boxDynamic(n, m, goods);

    while (i != 0)
    {
        if (algorithm[i][j] != algorithm[i - 1][j])
        {
            result_out.push_back(i);
            j -= goods[i].weight;
        }

        i--;
    }

    return result_out;
}

int main(int argc, char const *argv[])
{
    Goods *goods = new Goods[5]{
        Goods{20, 5},
        Goods{50, 8},
        Goods{70, 5},
        Goods{50, 2},
        Goods{40, 78}};

    vector<int> resultOut = result(5, 10, goods);
    cout << resultOut.size() << endl;

    for (int i = 0; i < resultOut.size(); i++)
        cout << resultOut[i] << " ";

    return 0;
}
