#include <bits\stdc++.h>

using namespace std;

int char_in_string(string s, char t)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == t)
            return i;

    return -1;
}

bool BoyerMooreHorspool(string string_have, string search)
{
    int z = search.length(), i = z - 1;

    while (i < string_have.size())
    {
        int j = z - 1;

        while (j >= 0 and string_have[i] == search[j])
        {
            i--;
            j--;
        }

        if (j < 0)
            return true;

        else
        {
            int tmp = char_in_string(search, string_have[i]);

            if (tmp < 0)
                i += z;

            else
                i += z - tmp - 1;
        }
    }

    return false;
}

struct Laptop
{
    string manufacture;
    string configuration;
    int sizeLaptop;
    int price;
};

int **table_result(int price, int number, Laptop *laptop)
{
    int **result = new int *[number + 1];

    for (int i = 0; i <= number; i++)
        result[i] = new int[price + 1];

    for (int i = 0; i <= price; i++)
        result[0][i] = 0;

    for (int i = 1; i <= number; i++)
        for (int j = 0; j <= price; j++)
        {
            result[i][j] = result[i - 1][j];

            if (laptop[i].sizeLaptop <= j)
            {
                int tmp = result[i][j - laptop[i].sizeLaptop] + laptop[i].price;

                if (tmp > result[i][j])
                    result[i][j] = tmp;
            }
        }

    return result;
}

vector<Laptop> query_result(int price, int number, Laptop *laptop)
{
    int i = number, j = price;
    vector<Laptop> resultLaptop;
    int **result = table_result(price, number, laptop);

    while (i != 0)
    {
        if (result[i][j] != result[i - 1][j])
        {
            resultLaptop.push_back(laptop[i - 1]);
            j -= laptop[i].sizeLaptop;
        }

        i--;
    }
    
    return resultLaptop;
}

int main(int argc, char const *argv[])
{
    return 0;
}
