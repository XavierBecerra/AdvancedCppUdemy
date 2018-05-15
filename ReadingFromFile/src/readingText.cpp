#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inFile;
    std::string fileName = "../etc/file.txt";

    bool pStdGetline = false;

    inFile.open(fileName.data());

    if( inFile.is_open() )
    {
        std::string line;
        char line2[256];

        while( !inFile.eof() ) // using while(inFile) does not work equally. See http://www.cplusplus.com/reference/fstream/ifstream/
        {
            if(pStdGetline)
            {
                std::getline(inFile, line);
                std::cout<< line << std::endl;
            }
            else
            {
                inFile.getline(line2, 256);
                std::cout<< line2 << std::endl;
            }
        }
        
        inFile.close();
    }
    else
    {
        std::cout<<"Could not open file "<< fileName.data()<< std::endl;
    }
    
    return 0;
}