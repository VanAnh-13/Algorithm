#include <bits\stdc++.h>

using namespace std;

struct Laptop
{
    string name;
    string configration;
    int price;
};

int char_in_string(string z, char t)
{
    for (int i = 0; i < z.length(); i++)
        if (z[i] == t)
            return i;

    return -1;
}

int F1(string z, string search)
{
    int searchSize = search.size(), i = searchSize - 1;

    while (i < z.length())
    {
        int j = searchSize - 1;

        while (z[i] == search[j] and j >= 0)
        {
            j--;
            i--;
        }

        if (j < 0)
            return i + 1;

        else
        {
            int v = char_in_string(search, z[i]);

            if (v < 0)
                i += searchSize;

            else
                i += searchSize - v - 1;
        }
    }

    return -1;
}

void z_algorithm(string z, int *result)
{
    int n = z.size(), l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;

            while (r < n and z[r - l] == z[r])
                r++;

            result[i] = r - l;
            r--;
        }

        else if (result[i - l] < r - i + 1)
            result[i] = result[i - l];

        else
        {
            l = 0;

            while (r < n and z[r - l] == z[r])
                r++;

            result[i] = r - l;
            r--;
        }
    }
}

int F3(Laptop *laptop, int n)
{
    vector<Laptop> vector;

    for (int i = 0; i < n; i++)
        if (F1(laptop[i].configration, "RAM 16GB") != -1)
            vector.push_back(laptop[i]);

    return vector.size();
}

vector<Laptop> F4(Laptop *laptop, int n)
{
    vector<Laptop> vectorResult;

    for (int i = 0; i < n; i++)
    {
        string search = "SSD";
        string z = search + "." + laptop[i].configration;
        int *result = new int[z.size()];
        z_algorithm(z, result);

        for (int j = search.size(); j < z.length(); j++)
            if (result[j] == search.length())
                vectorResult.push_back(laptop[i]);

        delete result;
    }

    return vectorResult;
}

int main(int argc, char const *argv[])
{
    Laptop laptop[] = {
        {"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
        {"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 1TB", 12000000},
        {"SamSung", "CPU 3.5GHz upto 4.5GHz-RAM 8GB-HDD 2TB", 20000000},
        {"LG", "CPU 3.8GHz upto 5GHz-RAM 16GB-SSD 256GB", 30000000},
        {"ACER", "CPU 4GHz upto 5GHz-RAM 8GB-SSD 128GB", 18000000},
        {"SamSung", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 512GB", 20000000},
    };

    int n = sizeof(laptop) / sizeof(laptop[0]);

    cout << F3(laptop, n) << endl;

    vector<Laptop> vectorResult = F4(laptop, n);

    cout << vectorResult.size() << endl;

    for (int i = 0; i < vectorResult.size(); i++)
        cout << vectorResult[i].name << " " << vectorResult[i].configration << " "
             << vectorResult[i].price << endl;

    return 0;
}
