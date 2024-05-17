#include <bits\stdc++.h>

using namespace std;

void println(char *s, int *a, int n)
{
    for (int i = 1; i <= n; i++)
        cout << s[a[i] - 1] << " ";
    cout << endl;
}

void init(int *a, int number)
{
    for (int i = 1; i <= number; i++)
        a[i] = i;
}

void next_conflig(int *a, int n, int index)
{
    ++a[index++];

    while (index <= n)
        a[index++] = a[index - 1] + 1;
}

void A3(int *a, char *s, int n, int k, int &count)
{
    int i;

    do
    {
        count++;
        println(s, a, k);

        i = k;

        while (i > 0 and a[i] == n - k + i)
            i--;

        if (i > 0)
            next_conflig(a, n, i);

    } while (i > 0);
}

void A4(int *a, char *s, int n, int k, int vt, int &count)
{
    if (k + 1 == vt)
    {
        count++;
        println(s, a, k);
        return;
    }

    for (int i = a[vt - 1] + 1; i <= n - k + vt; i++)
    {
        a[vt] = i;
        A4(a, s, n, k, vt + 1, count);
    }
}

int main()
{
    char s[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int size = 7;
    int count = 0;
    int k = 6;
    int *d = new int[k + 1]{0};

    // init(d, k);
    // A3(d, s, size, k, count);

    A4(d, s, size, k, 1, count);

    // tryK(a, s, size, k, 1, count);
    std::cout << "Tổng số cách lấy các kí tự trong S là: " << count << std::endl;
}