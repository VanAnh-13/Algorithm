#include <bits\stdc++.h>

using namespace std;

int D(double *a, int n, double C, vector<double> &result)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < C)
        {
            C -= a[i];
            result.push_back(a[i]);
        }
    }

    return result.size();
}

int char_in_string(char t, string z)
{
    for (int i = 0; i < z.size(); i++)
        if (z[i] == t)
            return i;

    return -1;
}

bool BoyerMooreHourspool(string Q, string P)
{
    int z = Q.size(), i = z - 1;

    while (i < P.size())
    {
        int j = z - 1;

        while (Q[j] == P[i] and j >= 0)
        {
            i--;
            j--;
        }

        if (j < 0)
            return true;

        else
        {
            int tmp = char_in_string(P[i], Q);

            if(tmp < 0)
                i += z;

            else 
                i += z - tmp - 1;
        }
    }

    return false;
}

int main()
{
    double a[] = {
        1.1,
        2.2,
        3.3,
        4.4,
        5.5,
        6.6,
        7.7,
        8.8,
    };

    int n = sizeof(a) / sizeof(a[0]);
    double C = 11.2;
    vector<double> result;

    if (D(a, n, C, result) > 0)
    {
        cout << "Co tat ca " << result.size() << " phan tu \n";

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    }
    else
        cout << "Khong co phan tu nao thoa man dieu kien \n";

    string P = "Le Van Anh";
    string Q = "Le Van";

    if(BoyerMooreHourspool(Q, P)) 
        cout << endl << "Yes" << endl;

    else 
        cout << endl << "No" << endl;
}