#include <iostream>
#include <vector>

using namespace std;

struct Flight
{
    std::string flightNumber;
    int price;
    std::string destination;

    void output()
    {
        std::cout << this->flightNumber << " " << this->price << " " << this->destination << std::endl;
    }
};

void A1(std::vector<Flight> &v1, Flight *flight, int length)
{
    if (length == 0)
        return;

    if (flight[length].price >= 700000)
    {
        v1.push_back(flight[length]);
    }

    A1(v1, flight, length - 1);
}

Flight A2(Flight *flight, int left, int right)
{
    if (left == right)
        return flight[left];

    int middle = (left + right) / 2;

    Flight minLeft = A2(flight, left, middle);
    Flight minRight = A2(flight, middle + 1, right);

    return (minLeft.price < minRight.price) ? minLeft : minRight;
}

void println(int *a, int size, Flight *flight)
{
    for (int i = 1; i <= size; i++)
        flight[a[i - 1]].output();
}

void A3(int *a, Flight *flight, int n, int k, int vt,int &count)
{
    if (k + 1 == vt)
    {
        count++;
        println(a, k, flight);
        return;
    }

    for (int i = a[vt - 1] + 1; i <= n - k + vt; i++)
    {
        a[vt] = i;
        A3(a, flight, n, k, vt + 1, count);
    }
    
    
}

int main()
{
    Flight *flight = new Flight[9]{
        Flight{"VN009", 20000, "09"},
        Flight{"VN008", 2000000, "08"},
        Flight{"VN007", 700, "07"},
        Flight{"VN006", 1000000, "06"},
        Flight{"VN005", 4000000, "05"},
        Flight{"VN004", 10000000, "04"},
        Flight{"VN003", 5000000, "03"},
        Flight{"VN002", 89000000, "02"},
        Flight{"VN001", 9000000, "01"},
    };

   // std::vector<Flight> v1;

    // A1(v1, flight, 8);

    // for (int i = 0; i < v1.size(); i++)
    //     v1[i].output();

    // Flight minFlight = A2(flight, 0, 8);
    // minFlight.output();

    int count = 0;
    int k = 4;

    int *a = new int[k]{0};

    A3(a, flight, 9, k, 1, count);

    cout << count << endl;

    delete[] flight;
}