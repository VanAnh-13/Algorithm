#include <iostream>

using namespace std;

long fibo(int number)
{
    if (number == 1 || number == 2)
        return 1;

    return fibo(number - 1) + fibo(number - 2);
}

long fibo1(int number)
{
    int *a = new int[number + 1]{0};
    a[1] = a[2] = 1;

    for (int i = 3; i <= number; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    return a[number];
}

int main()
{
    cout << "Nhập số cần tính: ";
    int number;
    cin >> number;

    cout << fibo(number) << endl;
    cout << fibo1(number);
}