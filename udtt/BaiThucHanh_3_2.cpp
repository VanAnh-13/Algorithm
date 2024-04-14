#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(double *&a, int l, int m, int r)
{
    vector<double> vt1(a + l, a + m + 1);
    vector<double> vt2(a + m + 1, a + r + 1);

    int i = 0, j = 0;

    while (i < vt1.size() && j < vt2.size())
    {
        if (vt1[i] >= vt2[j])
            a[l++] = vt2[j++];
        else
            a[l++] = vt1[i++];
    }

    while (i < vt1.size())
        a[l++] = vt1[i++];

    while (j < vt2.size())
        a[l++] = vt2[j++];
}

void mergeSort(double *a, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main()
{
    int sort1;
    cout << "Sum of number sort: ";
    cin >> sort1;

    double *array = new double[sort1];
    	srand(time(NULL));

    for (int i = 0; i < sort1; i++)
        array[i] =  rand() % 1000;

    for (int i = 0; i < sort1; i++)
        cout << array[i] << " ";

    mergeSort(array, 0, sort1 - 1);

    cout << endl;

    for (int i = 0; i < sort1; i++)
        cout << array[i] << " ";
}