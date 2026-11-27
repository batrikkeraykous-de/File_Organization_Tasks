#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fullName, id, grade;

    cout << "Enter Full Name: ";
    getline(cin, fullName);

    cout << "Enter ID: ";
    getline(cin, id);

    cout << "Enter Grade: ";
    getline(cin, grade);

    ofstream myfile("Student.txt");

    if (!myfile.is_open())
    {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    myfile << "Full Name: " << fullName << endl;
    myfile << "ID: " << id << endl;
    myfile << "Grade: " << grade << endl;

    myfile.close();

    cout << "Student data saved successfully" << endl;
    return 0;
}
