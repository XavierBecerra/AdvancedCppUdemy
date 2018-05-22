
#include <iostream>
#include "race.h"

using namespace std;
using namespace animals;

int main()
{
    cout<< "      Welcome to the Race!" <<endl;
    cout<< "Please insert how many KM will the race last: " <<endl;
    double totalDist = 0.0;
    cin >> totalDist;
    Race_t race(1000. * totalDist);

    race.announceRace();
    cout<< "Please type your bet for the winner" << race.getRunnersKeys() <<endl;
    string bet;
    cin >> bet;


    double dt = 0.1;

    Animal_t* winner = nullptr_t();
    while(!winner){
        winner = race.step(dt); 
    }

    race.showState();

    cout << endl;
    cout << "And the winner is.... The " << winner->getType() <<" !!! And says: " << flush;
    winner->speak();
    cout << endl;

    if(bet == winner->getType()) {
        cout << "GOOD BETTING! YOU WIN!"<< endl;
    }
    else {
        cout << "VERY BAD CHOISE...  YOU LOSE!"<< endl;
    }

    
    return 0;
}