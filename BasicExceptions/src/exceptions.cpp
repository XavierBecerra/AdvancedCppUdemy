#include <iostream>

void exceptionGenerator()
{
    bool error[3] = {false, false, true};

    if (error[0])
    {
        throw 21;
    }
    if (error[1])
    {
        throw "Fatal error";
    }
    if (error[2])
    {
        throw std::string("Fatal error string");
    }
}

void layerExceptionGenerator()
{
    exceptionGenerator();
}

int main()
{
    try
    {
        layerExceptionGenerator();
    }
    catch ( int e )
    {
        std::cout<< "Caught exception with error #" << e << std::endl;
    } 
    catch ( const char * e )
    {
        std::cout<< "Caught exception with error message: " << e << std::endl;
    }  
    catch ( std::string &e )
    {
        std::cout<< "Caught exception with error string message: " << e << std::endl;
    }      

    std::cout<< "Still Running" << std::endl;
}