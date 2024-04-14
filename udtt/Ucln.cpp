#include <iostream>

using namespace std;

long UCLN(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return UCLN(b % a, a);
}

long ucln(int a, int b)
{
    while (a != 0)
    {
        int tmp = b % a;
        b = a;
        a = tmp;
    }

    return b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << ucln(a, b) << endl;
    cout << UCLN(a, b);
}