#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string &filename)
{
    ifstream file(filename);

    string line;
    string text;
    if (file.good())
    {
        while (getline(file, line))
        {
            text += line;
            text += '\n';
        }
    }
    else
    {
        throw std::runtime_error("File could not be opened successfully.");
    }

    return text;
}

int main()
{
    cout << "This is anupurba's fork. " << endl;
    cout << "Reading configuration:" << endl;
    try
    {
        string text = readConfigFile("configuration.txt");
        cout << "This is anupurba's new code space named: Organic Lamp" << endl;
        cout << text;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
