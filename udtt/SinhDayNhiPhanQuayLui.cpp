#include <iostream>

using namespace std;

void println(int *a, int length)
{
    for (int i = 0; i < length; i++)
        cout << a[i];

    cout << endl;
}

void dayNhiPhan(int location, int length, int *binary)
{
    for (int i = 0; i <= 1; i++)
    {
        binary[location] = i;

        if (location == length - 1)
            println(binary, length);

        else
            dayNhiPhan(location + 1, length, binary);
    }
}

int main()
{
    int length;
    cout << "Nhap do dai cua day nhi phan: ";
    cin >> length;

    int *binary = new int[length];

    dayNhiPhan(0, length, binary);
}