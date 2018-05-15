#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input;
    std::string fileName = "../etc/file.txt";

    input.open(fileName.data());

    if(!input.is_open())
        return 1;

    while(!input.eof())
    {
        std::string line;
        int population = 0;

        //read string on the left of semicolon
        std::getline(input, line, ':');
        // read integer on the right side
        input >> population;
        //extract (read) the std::ws (in cpp 11 is to read whatever white space is there.)
        input >> std::ws;

        std::cout<< line << " -> " << population << std::endl;
    }


    return 0;
}