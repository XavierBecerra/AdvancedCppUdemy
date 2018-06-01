
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void run( function<bool(const string & )> check ) {//function states any callable object
    string test{"dof"};
    int count = check(test);
    cout << count << endl;
};

int main()
{
    vector< string > vect {"one", "two", "three"};

    int size = 3;
    auto pCheck = [size](const string & str) ->bool { 
        return str.size()==size; 
    };
    
    auto count = count_if(vect.begin() , vect.end(), pCheck);

    cout << count << endl;

    run(pCheck);

    function<int(int ,int)> add = [](int a, int b) {return a+b;};
    cout << add(2,3) << endl;
    
    return 0;
}