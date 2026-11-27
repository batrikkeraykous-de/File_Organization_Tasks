#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("names.txt");

    if (!in)
    {
        cout << "Error, unable to open the file" << endl;
        return 1;
    }

    string name;
    vector<string> names;

    while (getline(in, name))
    {
        if (!name.empty())
            names.push_back(name);
    }

    in.close();

    sort(names.begin(), names.end());

    ofstream out("sorted_names.txt");

    if (!out)
    {
        cout << "Error, unable to create the file" << endl;
        return 1;
    }

    cout << "Names sorted successfully" << endl;

    for (size_t i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
        out << names[i] << endl;
    }

    out.close();
    return 0;
}
