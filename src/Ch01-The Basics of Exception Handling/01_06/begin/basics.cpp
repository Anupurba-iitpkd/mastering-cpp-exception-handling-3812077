#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string& filename) 
{
    ifstream file(filename);

    string line;
    string text;
    while (getline(file, line)) 
    {
        text += line;
        text += '\n';
    }

    return text;
}

int main() 
{    
    cout << "This is anupurba's fork. "<< endl;
    cout << "Reading configuration:" << endl;
    string text = readConfigFile("configuration.txt");
    cout << "This is anupurba's new code space named: Organic Lamp"<<endl;
    cout << text;
    
    return 0;
}

