#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int findMinEven(int *a, int l, int r)
{
    if (l == r)
        return a[l] % 2 == 0 ? a[l] : INT_MAX;

    int m = (l + r) / 2;
    int minL = findMinEven(a, l, m);
    int minR = findMinEven(a, m + 1, r);

    int min = INT_MAX;
    if (minL != INT_MAX)
        min = minL;
    if (minR < min && minR != INT_MAX)
        min = minR;

    return min;
}

int main()
{
    srand(time(NULL));
    int sumOfArray = rand() % 30;

    int *array = new int[sumOfArray];

    for (int i = 0; i < sumOfArray; i++)
        array[i] = rand() % 101;

    for (int i = 0; i < sumOfArray; i++)
        cout << array[i] << " ";

    cout << "\nmin event: " << findMinEven(array, 0, sumOfArray - 1);
}