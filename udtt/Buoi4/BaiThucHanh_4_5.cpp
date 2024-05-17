#include <bits\stdc++.h>

using namespace std;

struct Work
{
    string id;
    int timeBegin;
    int timeNeed;

    void output()
    {
        cout << id << " " << timeBegin << " " << timeNeed << "\n";
    }
};

void A1(Work *work, int number)
{
    if (number == 0)
    {
        work[number].output();
        return;
    }

    work[number].output();

    A1(work, number - 1);
}

int A2(Work *work, int l, int r)
{
    if (l == r)
        return work[l].timeNeed <= 30;

    int m = (l + r) / 2;

    return A2(work, l, m) + A2(work, m + 1, r);
}

int main()
{
    Work *work = new Work[6]{
        Work{"001", 12, 20},
        Work{"002", 13, 10},
        Work{"003", 14, 15},
        Work{"004", 15, 17},
        Work{"005", 16, 35},
        Work{"006", 17, 36},
    };

    cout << A2(work, 0, 5);
}