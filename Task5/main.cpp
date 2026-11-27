#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    char name[20];
    int id;
    float grade;
    char delim;
};

int main()
{
    ofstream file("students.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        Student s;
        s.delim = '$';

        cout << "Enter Name: ";
        cin.getline(s.name, 20);

        if (cin.fail() && !cin.eof())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter ID: ";
        cin >> s.id;

        cout << "Enter Grade: ";
        cin >> s.grade;

        if (!cin)
        {
            cout << "Invalid input" << endl;
            return 1;
        }

        file << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Add another record? (y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');

        if (!cin)
            break;
    }

    file.close();

    cout << "Records saved successfully" << endl;
    return 0;
}
