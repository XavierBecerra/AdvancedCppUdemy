#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Start..."<< std::endl;

    std::ofstream outFile;
    //std::fstream outFile;
    std::string outFileName = "test.txt";

    outFile.open(outFileName.data() );

    //if we use class fstream (not ofsteam) we need to specify which type it is (ouput for ofstream) like:
    //outFile.open(outFileName.data(), std::ios::out);

    if( outFile.is_open() )
    {
        outFile << "Starting file." << std::endl; 
        outFile << "Writing number " << 23 << std::endl; 
        outFile.close();
    }
    else
    {
        std::cout << "File could not create file "<< outFileName.data() << std::endl; 
    }

    return 0;
}
