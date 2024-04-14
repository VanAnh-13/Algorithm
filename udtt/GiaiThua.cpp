#include <iostream>

using namespace std;

long long giaiThua(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * giaiThua(n - 1);
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "n! = " << giaiThua(n);
    return 0;
}