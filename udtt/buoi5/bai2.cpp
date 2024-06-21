#include <bits\stdc++.h>

using namespace std;

bool A2(int d, int *bottle, int n)
{
    int i = 0;

    while (d >= bottle[i] and i <= n) {
        d -= bottle[i];
        i++;
    }

    cout << "---------so cach do-------------" << i << endl;

    return d == 0;
}

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "bottle[" << i + 1 << "]: ";
        cin >> a[i];
    }

    int d;
    cin >> d;

    if (A2(d, a, n))
    {
      cout << "yes" << endl;
    }
    else
        cout << "Khong co cach chon !";
}