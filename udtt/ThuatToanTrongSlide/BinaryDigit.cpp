#include <iostream>
#include <string>

using namespace std;

void nextConflic(int *&a, int number, int index)
{
    a[index] = 1;

    index++;

    for (int i = index; i <= number; i++)
    {
        a[i] = 0;
    }
}

void print(int *a, int number)
{
    for (int i = 1; i <= number; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void binaryDigit(int n)
{
    int index;
    int *a = new int[n + 1] {0};

    do
    {
        print(a, n);
        
        index = n;
        
        while (index > 0 && a[index] == 1)
        {
            index--;
        }

        if (index > 0)
        {
            nextConflic(a, n, index);
        }
    } while (index > 0);
    
}

int main()
{
    int n;
    cout << "Enter the number of binary digits: ";
    cin >> n;

    binaryDigit(n);

    return 0;
}