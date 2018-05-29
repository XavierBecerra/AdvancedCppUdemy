
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto texts = {"one", "two", "three"};

    for ( auto text : texts){//texts has to be std iterable.
    cout << text << " , " << flush;

    }
    cout<<endl;

    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);
    for ( auto nr : numbers){//texts has to be std iterable.
    cout << nr << " , " << flush;

    }
    cout<<endl;

    string mystring = "Hello World";
    for ( auto letter : mystring){//texts has to be std iterable.
    cout << letter << " , " << flush;

    }
    cout<<endl;

    return 0;
}