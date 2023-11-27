#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Open the file
    ifstream inputFile("test.txt");

    // Check if the file is open
    if (!inputFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Read and print each line
    string line;
    string profname;
    vector<int> ugcdc;
    while (getline(inputFile, line))
    {
        profname = line;
    }

    // Close the file
    inputFile.close();

    return 0;
}