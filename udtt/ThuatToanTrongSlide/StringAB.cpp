#include <iostream>

using namespace std;

void nextConflic(string &a, int index, int number)
{
    a[index] = 'b';

    for (int i = index + 1; i < number; i++)
        a[i] = 'a';
}

void generateString(int n)
{
    string a(n, 'a');

    int index;

    do
    {
        cout << a << endl;

        index = n - 1;

        while (index > 0 && a[index] == 'b')
            --index;

        if (index > 0)
            nextConflic(a, index, n);

    } while (index > 0);
}

int main()
{
    int number;
    cout << "Enter length string: ";
    cin >> number;
    generateString(number);
    return 0;
}
