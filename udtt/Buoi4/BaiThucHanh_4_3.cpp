#include <iostream>
#include <ctime>
#include <cstdlib>

int pattion(int *a, int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (a[i] > pivot);

        do
        {
            --j;
        } while (a[j] < pivot);

        if (i < j)
            std::swap(a[i], a[j]);

        else
            return j;
    }
}

void quickSort(int *a, int l, int r)
{
    if (l >= r)
        return;

    int pivot = pattion(a, l, r);
    quickSort(a, l, pivot);
    quickSort(a, pivot + 1, r);
}

struct Call
{
    int left;
    int right;
};

struct Stack
{
    int top;
    Call *e;
};

void init(Stack &s)
{
    s.top = -1;
    s.e = new Call[1];
}

bool empty(Stack s)
{
    return (s.top == -1);
}

void push(Stack &s, Call call_in)
{ // Day mot phan tu
    // Cap phat bo nho cho mang e
    if (empty(s))
    {
        s.e = new Call[1];
    }
    else
    {
        // Cap phat them mot phan tu, cho mot loi goi
        s.e = (Call *)realloc(s.e, (s.top + 2) * sizeof(Call));
    }
    s.top++;
    s.e[s.top] = call_in;
}

void pop(Stack &s, Call &call_out)
{ // Lay mot phan tu
    if (empty(s))
        return;

    call_out = s.e[s.top];

    if (s.top == 0)
    { // Lay ra va het, khoi tao ngan xep
        delete[] s.e;
        init(s);
    }
    else
    { // Van con, cap phat giam 1 phan tu
        s.e = (Call *)realloc(s.e, s.top * sizeof(Call));
        s.top--;
    }
}

void sort(int *a, int n)
{
    Call x = {0, n - 1};
    Stack s;
    init(s);
    push(s, x);
    while (!empty(s))
    {
        pop(s, x);
        if (x.left < x.right)
        {
            int mid = (x.left + x.right) / 2;
            int chot = a[mid];
            int i = x.left, j = x.right;

            do
            {
                while (a[i] < chot)
                    i++;

                while (a[j] > chot)
                    j--;

                if (i <= j)
                {
                    std::swap(a[i], a[j]);
                    i++;
                    j--;
                }
            } while (i <= j);

            Call y1 = {x.left, j};
            Call y2 = {i, x.right};
            push(s, y2);
            push(s, y1);
        }
    }
}

int main()
{
    int n;
    std::cout << "Nhap so phan tu cua mang: ";
    std::cin >> n;

    int *array = new int[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        array[i] = rand() % 1000;

    sort(array, n);

    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}