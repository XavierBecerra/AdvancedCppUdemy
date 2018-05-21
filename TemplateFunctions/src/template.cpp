
#include <iostream>
#include <utility>


//Template functions and template classes can be mixed.
template<typename T> // you can use classes or typenames
void my_print(T in) {
    std::cout << in << std::endl;
};

void my_print(int in, bool use = false) {
    if(use) {
        std::cout << " Not using template function "<< in << std::endl;
    }
    else {
        std::cout << " Still not using template function "<< in << std::endl;
    }
    
};

void my_print(std::pair <int, double> in)  {
    std::cout << in.first << " : "<< in.second << std::endl;
};


template<typename T> 
void show() {
    std::cout << T() << std::endl;
};

int main()
{
    my_print<int>(5);
    my_print<int>(5.5);
    my_print<double>(5.5);

    my_print("Hi There");

    my_print(5, true);
    my_print(5);
    my_print<>(5);
    my_print(5.5);

    // std::pair does not habe operator<< overloaded, hence compilation error.
    my_print(std::make_pair<int,double>(8, 8.8) );

   // show();// noneof those will compile because template T is not in the argument list, so in case typename/class not specified inside <>, cpp compiler cannot figure it out from arglist
   // show<>();// noneof those will compile because template T is not in the argument list
    show<double>();

    return 0;
}