#include <iostream>

using namespace std;

void println(int *permutation, int length)
{
    for (int i = 0; i < length; i++)
        cout << permutation[i];
    cout << endl;
}

void lietKeHoanVi(int location, int length, int *permutation, int *tick)
{
    for (int i = 0; i < length; i++)
    {
        if (!tick[i])
        {
            permutation[location] = i;

            if (location == length - 1)
                println(permutation, length);
            

            else
            {
                tick[i] = 1;
                lietKeHoanVi(location + 1, length, permutation, tick);
                tick[i] = 0;
            }
        }
    }
}

int main()
{
    int length;
    cout << "Nhap do dai cua chuoi hoan vi: ";
    cin >> length;

    int *permutation = new int[length];
    int *check = new int[length]{0};

  lietKeHoanVi(0, length, permutation, check);
}