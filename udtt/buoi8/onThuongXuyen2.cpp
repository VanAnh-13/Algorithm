#include <bits\stdc++.h>

using namespace std;

struct Laptop
{
    string name;
    string manufacture;
    int length;
    int price;
};

struct LaptopGet
{
    int total;
    Laptop *laptop;
};

bool comparator(Laptop a, Laptop b)
{
    return a.length < b.length;
}

vector<LaptopGet> laptopGet(int total, Laptop *laptop, int priceHave)
{
    sort(laptop, laptop + total, comparator);
    vector<LaptopGet> vtGet;
    int i = 0;

    while (i < total and priceHave)
    {
        vtGet.push_back({priceHave / laptop[i].price, &laptop[i]});
        priceHave %= laptop[i].price;
        i--;
    }
    return vtGet;
}

bool laptop_get(int total, Laptop *laptop, int priceHave, vector<LaptopGet> &result)
{
    sort(laptop, laptop + total, comparator);

    for (int i = total - 1; i >= 0; i--)
    {
        if (priceHave >= laptop[i].price)
        {
            priceHave -= laptop[i].price;
            result.push_back({i, &laptop[i]});
        }
    }

    return priceHave >= 0;
}

bool laptop_get_2(int total, Laptop *laptop, int priceHave, vector<LaptopGet> &result)
{
    sort(laptop, laptop + total, comparator);

    for (int i = total - 1; i >= 0; i++)
    {
        priceHave -= laptop[i].price;
        result.push_back({i, &laptop[i]});

        if (priceHave < 0)
            return true;
    }

    return false;
}

int **result(int total, int price, Laptop *laptop)
{
    int **a = new int *[total + 1];

    for (int i = 0; i <= total; i++)
        a[i] = new int[price + 1];

    for (int i = 0; i <= price; i++)
        a[0][i] = 0;

    for (int i = 1; i <= total; i++)
        for (int j = 0; j <= price; j++)
        {
            a[i][j] = a[i - 1][j];

            if (j >= laptop[i].length)
            {
                int tmp = a[i][j - laptop[i].length] + laptop[i].price;

                if (tmp > a[i][j])
                    a[i][j] = tmp;
            }
        }

    return a;
}

vector<LaptopGet> query_result(int total, int price, Laptop *laptop)
{
    int i = total, j = price;
    int **a = result(total, price, laptop);
    vector<LaptopGet> result_get;

    while (i != 0)
    {
        if (a[i][j] != a[i - 1][j])
        {
            result_get.push_back({price / laptop[i].price, &laptop[i]});
            price %= laptop[i].price;
            j -= laptop[i].length;
        }

        i--;
    }

    return result_get;
}

int char_in_string(string s, char z)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] == z)
            return i;

    return -1;
}

int boyerMooreHorspool(string z, string search)
{
    int a = search.length(), i = a - 1;

    while (i < z.size())
    {
        int j = a - 1;

        while (search[j] == z[i] and j >= 0)
        {
            j--;
            i--;
        }

        if (j < 0)
            return i + 1;

        else
        {
            int k = char_in_string(search, z[i]);

            if (k < 0)
                i += a;
            else
                i += a - k - 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    Laptop laptop[] = {
        {"Thinkbook", "LG", 50, 10000000},
        {"Macbook pro", "Apple", 80, 80000000},
        {"Asus Zenbook", "Asus", 40, 15000000},
        {"Acer Predetor", "Acer", 70, 70000000},
    };

    int number = sizeof(laptop) / sizeof(laptop[0]);
    int priceHave = 30000000;
    vector<LaptopGet> result;
    laptop_get_2(number, laptop, priceHave, result);

    for (int i = 0; i < result.size(); i++)
        cout << result[i].total << " " << result[i].laptop->manufacture << " " << result[i].laptop->name << " " << result[i].laptop->price << endl;

    return 0;
}
