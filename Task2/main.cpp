#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("fruit.txt");

    if (!in.is_open())
    {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    string line, content;

    while (getline(in, line))
    {
        cout << line << endl;
        content += line + "\n";
    }

    in.close();

    ofstream out("fruit.txt");
    out << content << "Fresh Fruits" << endl;
    out.close();

    cout << "Fresh Fruits" << endl;
    return 0;
}
