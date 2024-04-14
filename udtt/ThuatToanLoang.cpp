#include <iostream>

using namespace std;

bool visited[1000][1000] = {false};

void loang(int x, int y)
{
    if (visited[x][y])
        return;

    visited[x][y] = {true};

    if (x > 0 && !visited[x - 1][y])
    {
        cout << "Đi lên trên" << endl;
        loang(x - 1, y);
    }
    else if (y > 0 && !visited[x][y - 1])
    {
        cout << "Đi qua bên trái" << endl;
        loang(x, y - 1);
    }
    else if (x < 4 && !visited[x + 1][y])
    {
        cout << "Đi xuống dưới" << endl;
        loang(x + 1, y);
    }
    else if (y < 5 && !visited[x][y + 1])
    {
        cout << "Đi sang phải" << endl;
        loang(x, y + 1);
    }
}

int main() {
    loang(0,0);
}