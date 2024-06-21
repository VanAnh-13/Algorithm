#include <iostream>

using namespace std;

int analys03(int number, int sum)
{
    int *f = new int[number + 1]();
    f[0] = 1;

    for (int i = 1; i <= number; i++)
        f[i] = 0;

    for (int i = 1; i <= sum; i++)
        for (int j = i; j <= number; j++)
            if (i <= j)
                f[j] += f[j - i];

    return f[number];
}

int main()
{
    cout << analys03(5, 5) << endl;
    return 0;
}
