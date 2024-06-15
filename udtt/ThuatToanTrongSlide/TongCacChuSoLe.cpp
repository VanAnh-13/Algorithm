#include<iostream>

using namespace std;

long sumOdd(int n)
{
    if (n == 0)
        return 0;

    if (n % 2 == 0)
        return sumOdd(n / 10);
    else
        return n % 10 + sumOdd(n / 10);
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << sumOdd(n);
}