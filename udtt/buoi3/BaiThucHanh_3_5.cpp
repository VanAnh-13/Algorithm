#include <iostream>
#include <ctime>
#include <random>

using namespace std;

double sum(double *a, int l, int r)
{
    if (l == r)
        return a[l];

    int m = (l + r) / 2;
    double sum1 = sum(a, l, m);
    double sum2 = sum(a, m + 1, r);

    return sum1 + sum2;
}

int main()
{
    srand(time(NULL));
    int number = rand() % 30;

    double *array = new double[number];

    for (int i = 0; i < number; i++)
        array[i] = rand() % 101;

    for (int i = 0; i < number; i++)
        cout << array[i] << " ";

    cout << "\nsum = " << sum(array, 0, number - 1);

    return 0;
}