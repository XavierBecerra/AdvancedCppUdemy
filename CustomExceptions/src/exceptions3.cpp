#include <iostream>
#include <exception>

class OwnException: public std::exception
{
public:
    virtual const char* what() const throw() 
    {
        return "Something bad happened";
    };
    //const throw() means that this method will NOT throw an exception. So compiler can optimize code because
    // it knows this code will not throw)
    // Not a good practice in general: This will lead to runtime erros and not compile time errors.
    // fyi: java has the compile time checking on type of exceptions that can be thrown
};

class Test
{
public:
    void throwOwnException()
    {
        throw OwnException();
    }
    void noThrowOwnException() throw(std::bad_alloc)
    {
        // This will produce a runtime error, since from a method that can only throw bad_alloc, we thorw another exception.
        throw OwnException();
    }
};

int main()
{
    Test test;

    try
    {
        test.throwOwnException();
    }
    catch(OwnException &e)
    {
        std::cout<< "Caught exception: " << e.what() << std::endl;
    }

    std::cout<< "Still Running" << std::endl;

    // Now lets get the runtime error 
    try
    {
        test.noThrowOwnException();
    }
    catch(OwnException &e)
    {
        std::cout<< "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}