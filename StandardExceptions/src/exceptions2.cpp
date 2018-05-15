#include <iostream>

class CouldFail_t
{
public:
    CouldFail_t() {
        //new will throw if to memory is allocated.
        char * pMemory = new char[99999999999999999];
        delete [] pMemory;

        //using exceptions on construction is a good mechanism of catching possible errors.
        // because we cannot get a return call from a constructor to say sth went wrong (usign e.g. pMemory = null)
    }
};

int main()
{
    try
    {
        CouldFail_t testExeption;
    }
    catch(std::bad_alloc &e)
    {
        std::cout<< "Caught exception: " << e.what() << std::endl;
    }

    std::cout<< "Still Running" << std::endl;

    return 0;
}