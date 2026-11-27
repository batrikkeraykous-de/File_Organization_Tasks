#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int grade;

    ofstream out("grades.txt");

    if (!out)
    {
        cout << "Error, unable to create the file" << endl;
        return 1;
    }

    cout << "Enter 5 integer grades:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Grade " << i + 1 << ": ";
        cin >> grade;

        if (cin.fail())
        {
            cout << "Error, invalid grade" << endl;
            return 1;
        }

        out << grade << endl;
    }

    out.close();

    ifstream in("grades.txt");

    if (!in)
    {
        cout << "Error, unable to open the file" << endl;
        return 1;
    }

    cout << "\nGrades in the file:" << endl;

    while (in >> grade)
    {
        cout << grade << endl;
    }

    in.close();

    int target;
    cout << "\nEnter the grade you want to delete: ";
    cin >> target;

    if (cin.fail())
    {
        cout << "Error, invalid grade" << endl;
        return 1;
    }

    in.open("grades.txt");
    ofstream temp("temp.txt");

    if (!in || !temp)
    {
        cout << "Error, unable to open the files" << endl;
        return 1;
    }

    bool found = false;

    while (in >> grade)
    {
        if (grade != target)
            temp << grade << endl;
        else
            found = true;
    }

    in.close();
    temp.close();

    if (!found)
    {
        remove("temp.txt");
        cout << "Error, grade not found" << endl;
        return 1;
    }

    if (remove("grades.txt") != 0 || rename("temp.txt", "grades.txt") != 0)
    {
        cout << "Error, unable to replace the file" << endl;
        return 1;
    }

    cout << "Grade deleted successfully" << endl;

    in.open("grades.txt");
    cout << "\nGrades after deletion:" << endl;

    while (in >> grade)
    {
        cout << grade << endl;
    }

    in.close();
    return 0;
}
