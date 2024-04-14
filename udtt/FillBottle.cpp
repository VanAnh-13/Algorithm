#include <iostream>
#include <algorithm>

using namespace std;

bool pouring(int jug, int *bottle, int number)
{
    sort(bottle, bottle + number);
    int i = 0;

    while (jug >= bottle[i] && i <= number)
    {
        jug -= bottle[i];
        i++;
    }

    cout << "i = " << i << endl;

    if (i > 0)
        return true;
    else
        return false;
}

int main()
{
    int jug = 10;
    int bottle[] = {8 , 5, 4, 3, 2};
    int number = sizeof(bottle) / sizeof(bottle[0]);

    if (pouring(jug, bottle, number))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}