#include <iostream>

using namespace std;

long sum(int n)
{
    if (n == 0)
        return 0;

    return n % 10 + sum(n / 10);
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << sum(n);
}