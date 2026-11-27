#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "How many persons do you want to add? ";
    cin >> n;

    if (!cin || n <= 0)
    {
        cout << "Invalid number" << endl;
        return 1;
    }

    ofstream out("persons.txt");

    for (int i = 0; i < n; i++)
    {
        Person p;

        cin.ignore(1000, '\n');
        cout << "Enter Name: ";
        getline(cin, p.name);

        cout << "Enter Age: ";
        cin >> p.age;

        if (!cin)
        {
            cout << "Invalid age" << endl;
            return 1;
        }

        out << p.name << endl;
        out << p.age << endl;
    }

    out.close();

    ifstream in("persons.txt");
    vector<Person> persons;
    Person p;

    while (getline(in, p.name) && in >> p.age)
    {
        in.ignore(1000, '\n');
        persons.push_back(p);
    }

    in.close();

    Person younger = persons[0];
    Person older = persons[0];

    for (size_t i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < younger.age)
            younger = persons[i];

        if (persons[i].age > older.age)
            older = persons[i];
    }

    ofstream results("results.txt");
    results << "Younger: " << younger.name << ", " << younger.age << endl;
    results << "Older: " << older.name << ", " << older.age << endl;
    results.close();

    cout << "Younger: " << younger.name << ", " << younger.age << endl;
    cout << "Older: " << older.name << ", " << older.age << endl;
    return 0;
}
