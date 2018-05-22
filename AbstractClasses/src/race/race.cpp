
#include <iostream>
#include <cmath>
#include "race.h"

using namespace std;
using namespace animals;

Race_t::Race_t() : totalDist(0.0) , duration(0.0){

        try{
            setUpRunners( animals);
        }
        catch(exception & e){
            throw e;
        }
    };

Race_t::Race_t(const double & distance) : totalDist(distance), duration(0.0) {

        try{
            setUpRunners(animals);
        }
        catch(exception & e){
            throw e;
        }
    };

void Race_t::setUpRunners(map<string, Animal_t*> & animals){
    
        animals["Dog"] = new Dog_t();
        cout << "speed " << animals["Dog"]->getSpeed() << endl;
        animals["Hare"] = new Hare_t();
        animals["Turtle"] = new Turtle_t();
};

void Race_t::announceRace() const{

    cout << "The fairytale race is about to start!" << endl <<" The following runners will run " << totalDist << " meters:" << endl;
    showRunners();
    cout<< "Who will win?"<< endl;      
};

void Race_t::showRunners() const{

    int lane = 1;
    for (map<string, Animal_t*>::const_iterator it = animals.begin() ; it != animals.end(); it++)
    {
        cout << "On the lane #" << lane << " : " << it->first << endl;
        lane++;
    }
};

string Race_t::getRunnersKeys() const{

    string out = "[ ";
    for (map<string, Animal_t*>::const_iterator it = animals.begin() ; it != animals.end(); it++)
    {
        out.append(it->first + ", ");
    }
    out.append("]");

    return out;
};

bool Race_t::hasArrived(Animal_t & animal, const double endDistance, const double dt)
{
    double animalDist = animal.run(dt);
    
    return (animalDist > endDistance);
};

Animal_t* Race_t::step(const double dt){
    //run all animals

    Animal_t *winner = nullptr_t();
    try {
        //if the dog is hungry and the hare is very close (aprox 2 meters)
        if(     animals.at("Dog")->isHungry() 
            &&  abs(animals.at("Dog")->getDistance() - animals.at("Hare")->getDistance()) < 10.0 ){
            //if the hare is not dead, dog eats it
            cout << "Dog (" << animals.at("Dog")->getDistance() << " m) wants to eat the Hare (" << animals.at("Hare")->getDistance() << endl;

            if( !animals.at("Hare")->isDead() ){

                animals.at("Hare")->killIt();
                animals.at("Dog")->eat();
            }
        }
    }
    catch (std::exception & e){
        cout<< e.what();
        throw;
    }


    for (map<string, Animal_t*>::iterator it = animals.begin() ; it != animals.end(); it++)
    {
        if(hasArrived(*it->second, totalDist, dt)){
            winner = it->second;
        }
    }

    duration += dt;
    if(fmod(duration, 150.0) <= 0.0001){
        showState();
    }

    return winner;
};

void Race_t::showState() const{

    for (map<std::string, Animal_t*>::const_iterator it = animals.begin() ; it != animals.end(); it++)
    {
        cout << "The " << it->first << " has run a distance of: " << it->second->getDistance() << " .And says: " << flush;
        it->second->speak(); 
        cout<< endl;
    }
};

Race_t::~Race_t(){
    
    for (map<std::string, Animal_t*>::iterator it = animals.begin() ; it != animals.end(); it++)
    {
        delete it->second; 
        it->second = nullptr_t();
    }
}