#include <iostream>

using namespace std;

void println(int *a, int number)
{
    for (int i = 0; i < number; i++)
        cout << a[i];
    cout << endl;
}

// Sinh cấu hình mới từ cấu hình đang có
void nextConflix(int *a, int i, int number)
{
    // Tìm a[k] bé nhất trong đoạn cuối mà vừa đủ lớn hơn x[i]
    int k = number;

    while (a[k] < a[i])
        k--;

    // Đổi chỗ a[k] với a[i]
    swap(a[k], a[i]);

    // Đảo ngược đoạn cuối
    int j = number;
    i++;

    while (j > i)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

// Liệt kê cấu hình
void viewConflix(int number)
{
    int j, *a = new int[number + 1]{0};

    for (int i = 1; i <= number; i++)
        a[i] = i;

    do
    {
        println(a, number);
        j = number - 1;

        // Tìm phần tử liền trước vị trí giảm dần
        while (j > 0 && a[j] > a[j + 1])
            j--;

        // Chưa phải cấu hình cuối
        if (j > 0)
            nextConflix(a, j, number);

    } while (j > 0);
}

int main()
{
    int number;
    cout << "Nhập độ dài của xâu hoán vị: ";
    cin >> number;

    viewConflix(number);
}