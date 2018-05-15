

//Focus: Catching exceptions in the right order.
// std::exception is parent class of std::bad_alloc : https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm

#include <iostream>
#include <exception>

void exceptionGenerator()
{
    bool error[3] = {true, false, false};

    if (error[0])
    {
        throw std::bad_alloc();
    }
    if (error[1])
    {
        throw std::exception();
    }
    if (error[2])
    {
    }
}

int main()
{
    try
    {
        exceptionGenerator();
    }/*
    This catch will also catch bad_alloc because it is a subclass of exception (polymorfism will make it hapen)
    Compiler spits out a warning
    catch ( std::exception &e )
    {
        std::cout<< "exception Caught " << e.what() << std::endl;
    } 
    */
    catch ( std::bad_alloc &e )
    {
        std::cout<< "bad_alloc Caught " << e.what() << std::endl;
    }      
    catch ( std::exception &e )
    {
        // here is where the parent class catch should be placed. after the subclass handler
        std::cout<< "exception Caught " << e.what() << std::endl;
    } 

    std::cout<< "Still Running" << std::endl;

    return 0;
}