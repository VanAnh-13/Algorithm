#include <iostream>
#include <algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;

double max(double *a, int l, int r)
{
    if (l == r)
        return a[l];
    
    int m = (l + r) / 2;

    double max1 = max(a, l, m);
    double max2 = max(a, m + 1, r);
    return max1 > max2 ? max1 : max2;
}

int main()
{
    int sort1;
    cout << "Sum of number: ";
    cin >> sort1;

    double *array = new double[sort1];
    srand(time(NULL));

    for (int i = 0; i < sort1; i++)
        array[i] = rand() % 1000;

    for (int i = 0; i < sort1; i++)
        cout << array[i] << " ";

    cout << "\nmax = " << max(array, 0, sort1 - 1);
}