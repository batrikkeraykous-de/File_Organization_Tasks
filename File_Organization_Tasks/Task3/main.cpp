#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("welcome.txt", ios::out);

    if (!file.is_open())
    {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    file << "Hello Everybody";
    file.close();

    file.open("welcome.txt", ios::in | ios::out);

    file.seekp(11, ios::beg);
    file << "one ";

    file.seekg(0, ios::beg);
    string text;
    getline(file, text);
    cout << text << endl;

    file.close();
    return 0;
}
