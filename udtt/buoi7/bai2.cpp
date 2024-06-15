#include <bits\stdc++.h>

using namespace std;

int countWord(string &t, string p = "child")
{
    int dem = 0, v = p.length(), i = v - 1;

    while (i < t.size())
    {
        int x = v - 1;

        while (t[i] == p[x] && x >= 0)
        {
            i--;
            x--;
        }

        if (x < 0)
        {
            dem++;
            t.replace(i + 1, v, "children");
            i += v + 1;
        }
        else
            i += v - x;
    }

    return dem;
}

int main()
{
    string t = "child 12345 child";
    cout << countWord(t) << " " << t << endl;
    return 0;
}