#include <bits\stdc++.h>

using namespace std;

vector<int> find(double *a, int n)
{
    a[0] = INT_MIN;
    a[n + 1] = INT_MAX;

    int *L = new int[n + 2];
    L[n + 1] = 1;
    vector<int> T(n + 2);

    for (int i = n; i >= 0; i--)
    {
        int jmax = n + 1;

        for (int j = i + 1; j <= n + 1; j++)
        {
            if (a[j] > a[i] and L[j] > L[jmax])
                jmax = j;

            L[i] = L[jmax] + 1;
            T[i] = jmax;
        }
    }

    delete[] L;

    return T;
}

void result(double *a, int n)
{
    vector<int> T = find(a, n);
    cout << "Day con: ";

    int k = T[0];

    while (k != n + 1)
    {
        cout << "a[" << k << "]: " << a[k] << " ";
        k = T[k];
    }
}

int main()
{
    double a[9];

    for (int i = 1; i <= 9; i++)
        cin >> a[i];

    int n = sizeof(a) / sizeof(a[0]);

    result(a, n);
}