#include <bits\stdc++.h>

using namespace std;

double sumArray(double *a, int l, int r)
{
    if (l == r)
        return a[l];

    int m = (l + r) / 2;

    double result_left = sumArray(a, l, m);
    double result_right = sumArray(a, m + 1, r);

    return result_left + result_right;
}

int main()
{
    int n = 5;
    double a[] = {
        1.3,
        5.8,
        9.7,
        3.5,
        4.5};

    cout << "Tong day chu so la: " << sumArray(a, 0, n - 1) << endl;
}