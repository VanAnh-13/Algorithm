#include <iostream>

using namespace std;

int sum(int *a, int n)
{
    if (n == 0)
        return 0;

    if (a[n - 1] % 2 != 0)
        return sum(a, n - 1) + a[n - 1];

    else
        return sum(a, n - 1);
}

int main()
{
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = sizeof(a) / sizeof(a[0]);

    cout << sum(a, n) << endl;
}