
#include <iostream>
#include "ringBuffer.h"

using namespace std;

//Ring Buffer, ring buffer

int main()
{
    RingBuffer_t<string> ring(3);
    ring.add("one");
    ring.add("two");
    ring.add("three");

    try {

        for( RingBuffer_t<string>::iterator obj = ring.begin(); obj != ring.end(); obj++ ) {
            cout<< *obj <<endl;
        }
        cout<<endl;

        ring.add("four");
        for( auto object : ring ) {
            cout<< object <<endl;
        }
    }
    catch(exception & e) {
        cout<< e.what() << endl;
    }

    cout<<endl;
    RingBuffer_t<string> ring2(3, {"hi", "how", "are", "you"});
    for( auto object : ring2 ) {
        cout<< object <<endl;
    }
    cout<<endl;

    RingBuffer_t<string> ring3(4, {"hi", "how", "are", "you"});
    for( auto object : ring3 ) {
        cout<< object <<endl;
    }
    cout<<endl;

    return 0;
}