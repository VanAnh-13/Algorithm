#include <bits\stdc++.h>

using namespace std;

bool symetryString(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

string xauConDoiXungDaiNhat(string s, int k)
{
    int left = k - 1;
    int right = k + 1;
    int maxLength = 1;
    int start = k;

    while (left >= 0 and right < s.size() and s[left] == s[right])
    {
        if (right - left > maxLength)
        {
            maxLength = right - left + 1;
            start = left;
        }

        left--;
        right++;
    }

    return s.substr(start, maxLength);
}

int main()
{
    string s = "a123c321aa";

    if (symetryString(s))
        cout << "Yes" << endl;

    else
    {
        cout << "Nhap k: ";
        int k;
        cin >> k;

        cout << xauConDoiXungDaiNhat(s, k) << endl;
    }
}
