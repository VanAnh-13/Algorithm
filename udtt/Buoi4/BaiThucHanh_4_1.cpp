#include <bits\stdc++.h>

using namespace std;

void init(int *array, int length)
{
    for (int i = 1; i <= length; i++)
        array[i] = i;
}

void println(string chair[], string student[], int leng, int *array)
{
    for (int i = 1; i <= leng; i++)
        cout << student[array[i] - 1] << " --- "
             << chair[i - 1] << " ";

    cout << endl;
}

void arrangeStudent(int *array, int length, int index)
{
    int k = length;

    while (array[k] < array[index])
        k--;

    swap(array[k], array[index]);

    reverse(array + index + 1, array + length + 1);
}

void arrangeStudentChair(string chair[], string student[], int length, int *array, int &sumOfCheck)
{
    int i;
    do
    {
        sumOfCheck++;
        println(chair, student, length, array);

        i = length - 1;
        while (i > 0 && array[i] > array[i + 1])
            i--;

        if (i > 0)
            arrangeStudent(array, length, i);

    } while (i > 0);
}

void tryK(int k, int length, int *array, string chair[], string student[], int *check, int &sumOfCheck)
{
    for (int i = 1; i <= length; i++)
    {
        if (!check[i])
        {
            array[k] = i;

            if (k == length)
            {
                sumOfCheck++;
                println(chair, student, length, array);
            }

            else
            {
                check[i] = 1;
                tryK(k + 1, length, array, chair, student, check, sumOfCheck);
                check[i] = 0;
            }
        }
    }
}

int main()
{
    string student[] = {"Tung", "Cuc", "Truc", "Mai"};
    string chair[] = {"A", "B", "C", "D"};
    int size = sizeof(student) / sizeof(student[0]);

    int *a = new int[size + 1];
    int *check = new int[size + 1]{0};
    int sumOfCheck = 0;
    init(a, size);
    arrangeStudentChair(chair, student, size, a, sumOfCheck);
    //    tryK(1, size, a, chair, student, check, sumOfCheck);
    cout << "Tong so cach sap xep " << sumOfCheck << endl;
}