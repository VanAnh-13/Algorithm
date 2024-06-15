#include<iostream>

using namespace std;

void thapHaNoi(int number, char A, char B, char C){
    if(number == 1){
        cout << A << " --------> " << C << endl;
        return;
    }

    thapHaNoi(number - 1, A, C, B);
    thapHaNoi(1, A, B, C);
    thapHaNoi(number - 1, B, A, C);
}

int main() {
    int number;
    cout << "Nhap sao tang cua thap:\n";
    cin >> number;

    thapHaNoi(number, 'A', 'B', 'C');
}