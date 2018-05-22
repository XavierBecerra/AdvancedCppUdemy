
#include <iostream>
#include <map>
#include "animals.h"

class Race_t
{
public:
    Race_t();
    Race_t(const double & distance);

    ~Race_t();

    void announceRace() const;
    std::string getRunnersKeys() const;
    animals::Animal_t* step(const double dt);
    void showState() const;

private: 
    void setUpRunners(std::map<std::string, animals::Animal_t*> & animals);
    void showRunners() const;
    bool hasArrived(animals::Animal_t & animal, const double endDistance, const double dt);

    std::map<std::string, animals::Animal_t*> animals;
    double totalDist;// in meter!
    double duration;// in seconds!
};
