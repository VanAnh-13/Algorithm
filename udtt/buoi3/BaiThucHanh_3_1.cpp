#include <iostream>

using namespace std;

class Student
{
private:
    string lastName;
    string firstName;
    int age;
    string address;

public:
    Student(string lastName, string firstName, int age, string address)
    {
        this->lastName = lastName;
        this->firstName = firstName;
        this->age = age;
        this->address = address;
    }

    Student(){
        this->lastName = "No Last Name";
        this->firstName = "No First Name";
        this->age = 0;
        this->address = "No address";
    }

    void display()
    {
        cout << "   Last name: " << lastName << endl;
        cout << "   First name: " << firstName << endl;
        cout << "   Age: " << age << endl;
        cout << "   Address: " << address << endl;
    }

    string getLastName()
    {
        return lastName;
    }

    string getFirstName()
    {
        return firstName;
    }
    int getAge()
    {
        return age;
    }
    string getAddress()
    {
        return address;
    }
};

int pattion(Student *a, int l, int r)
{
    Student pivot = a[l];
    int i = l - 1;
    int j = r + 1;

    while (true)
    {
        do
        {
            i++;
        } while (pivot.getLastName() > a[i].getLastName());

        do
        {
            j--;
        } while (pivot.getLastName() < a[j].getLastName());

        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            return j;
        }
    }
}

void quickSort(Student *student, int l, int r)
{
    if (l >= r)
        return;

    int pivot = pattion(student, l, r);
    quickSort(student, l, pivot);
    quickSort(student, pivot + 1, r);
}

Student findName(Student *st, int sumOfStudent, string nameFind)
{
    int l = 0, r = sumOfStudent, between = 0;
    Student stFind;

    while (l <= r)
    {
        between = l + r / 2;

        if (st[between].getLastName() == nameFind)
            stFind = st[between];
        else if (nameFind > st[between].getLastName())
            l = between + 1;
        else if (nameFind < st[between].getLastName())
            r = between - 1;
    }
    return stFind;
}

int main()
{
    int sumOfStudent = 6;
    Student *student = new Student[sumOfStudent];

    student[0] = Student("Anh", "Le Van", 18, "Ha Noi");
    student[1] = Student("Nam", "NGuyen Van", 19, "Ho Chi MInh");
    student[2] = Student("Hai", "Dinh Van", 20, "Hai Phong");
    student[3] = Student("Linh", "Le Nguyen Thi", 21, "Nam Dinh");
    student[4] = Student("Trang", "Bui Le Thi", 22, "Thai Binh");
    student[5] = Student("Huyen", "Mai Thi", 23, "Hoa Binh");


        quickSort(student, 0, sumOfStudent - 1);

    for (int i = 0; i < sumOfStudent; i++)
    {
        cout << "-------------------------------\n";
        student[i].display();
    }

    string name;
    cout << "-----Enter name find-----";
    cin >> name;

    Student find = findName(student, sumOfStudent - 1, name);
    find.display();

    return 0;
}