#include <iostream>
#include<ctime>
#include<random>

using namespace std;

double pow1(double a, int n)
{
    if (n == 1)
        return a;
    else
    {
        double index = pow(a, n / 2);

        if (n % 2 == 0)
            return index * index;
        else
            return index * index * a;
    }
}

int main()
{
    srand(time(NULL));
    int number = rand() % 11;
    double a = rand() % 100;
    
    cout << "a: " << a << ", number: " << number << endl;
    cout << "pow(a, number) = " << pow1(a, number) << endl;
}