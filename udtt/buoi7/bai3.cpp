#include <bits\stdc++.h>

using namespace std;

bool countWord(string &string_char, string word_count = "1000")
{
    int v = word_count.length(), i = v - 1;

    while (i < string_char.size())
    {
        int k = v - 1;

        while (k > -1 and string_char[i] == word_count[k])
        {
            i--;
            k--;
        }

        if (k < 0)
        {
            string_char.replace(i + 1, v, "mot nghin dong");
            return true;
        }

        else
            i += v - k;
    }

    return false;
}

int main()
{
    string z = "1000 2000 kiem tra 1000 test";

    if(countWord(z)) cout << "Yes\n" << z << endl;
    else cout << "No " << endl;

    return 0;
}
