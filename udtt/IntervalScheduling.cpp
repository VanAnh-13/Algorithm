#include <iostream>
#include <algorithm>

using namespace std;

class Interval
{
private:
    double start;
    double end;

public:
    Interval(double start, double end)
    {
        this->start = start;
        this->end = end;
    }

    Interval()
    {
        this->start = 0;
        this->end = 0;
    }

    double getStart()
    {
        return start;
    }

    double getEnd()
    {
        return end;
    }

    void setStart(double start)
    {
        this->start = start;
    }

    void setEnd(double end)
    {
        this->end = end;
    }
};

double *intervalScheduling(Interval *intervals, int n)
{
    sort(intervals, intervals + n, [](Interval a, Interval b)
         { return a.getEnd() < b.getEnd(); });

    double *schedule = new double[n]{0};
    int i = 0;
    double lastFinish = 0;

    while (i < n)
    {
        if (intervals[i].getStart() >= lastFinish)
        {
            schedule[i] = i;
            lastFinish = intervals[i].getEnd();
        }
        i++;
    }

    return schedule;
}

int main()
{
    int n = 5;
    Interval *intervals = new Interval[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Start " << i + 1 << ": ";
        double start;
        cin >> start;
        intervals[i].setStart(start);
        double end;
        cout << "End " << i + 1 << ": ";
        cin >> end;
        intervals[i].setEnd(end);
    }

    double *schedule = intervalScheduling(intervals, n);

    for (int i = 0; i < n; i++)
        cout << schedule[i] << " ";

    return 0;
}