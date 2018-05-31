
#include <iostream>

using namespace std;

class Test_t
{
private:
    int one{1};
    int two{2};

public: 
    void run(){
        int three{3};
        int four{4};

        //you cannot do [=, this]
        //you can do [&, this]
        auto pLambda = [this, three , four](){
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };

        pLambda();
    };
};

int main()
{
    Test_t test;
    test.run();
    
    return 0;
}