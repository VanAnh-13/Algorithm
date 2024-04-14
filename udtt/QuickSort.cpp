#include <iostream>

using namespace std;

int pattion(int *a, int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (a[i] < pivot);

        do
        {
            --j;
        } while (a[j] > pivot);

        if (i < j)
            swap(a[i], a[j]);

        else
            return j;
    }
}

void quickSort(int *a, int l, int r)
{
    if (l >= r)
        return;

    int pivot = pattion(a, l, r);
    quickSort(a, l, pivot);
    quickSort(a, pivot + 1, r);
}

int main()
{
    int n;
    cout << "Nhập số phần tử của mảng: ";
    cin >> n;

    int *a = new int [n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhập phần tử thứ " << i + 1 << ": ";
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}