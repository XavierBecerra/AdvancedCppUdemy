#include "animals.h"
using namespace std;

namespace animals
{
// ---- ANIMALS

Animal_t::Animal_t(const std::string & type, double spd ) : 
    type(type), 
    speed_setting(spd), 
    speed(spd),
    distance(0.) {};

std::string Animal_t::getType() const {
    return type;
};

double Animal_t::getDistance() const{
    return distance;
};

double Animal_t::getSpeed() const{
    return speed;
};

void Animal_t::stop(){
    speed = 0.0;
};

void Animal_t::restart(){
    speed = speed_setting;
};

//bool Animal_t::operator== (const Animal_t& obj) const
//{
//    return type == type;
//};

bool Animal_t::operator< (const Animal_t& obj) const
{
    return type < obj.type;
};

ostream & operator<< (ostream& out, const Animal_t& animal)
{
    out << animal.type << ", with a speed of : " << animal.speed << " m/s ";
    return out;
};


// ---- HARE
Hare_t::Hare_t() : Animal_t("Hare", 10.0) {  // TODO(Xavi) 10.0 meter per sec
    tired = false;
    dead = false;
};

void Hare_t::speak() const {
    cout << "I am a fast Hare" << flush;
    if(isTired()){
        cout << ", I am tired" << flush;   
    }
    if(isDead()){
        cout << ", I am dead" << flush;   
    }
};

bool Hare_t::isTired() const {
    return tired;
};

bool Hare_t::isDead() const {
    return dead;
};

void Hare_t::killIt() {
    dead = true;
    tired = false;
};

double Hare_t::run(const double dt) {
    if(distance > 1000. && !isDead() ) {
        tired = true;
    }

    if( isDead() ) {
        distance += 0.0;
    }
    else if ( isTired() ) {
        distance += 0.2 * speed * dt;
    }
    else {
        distance += speed * dt;
    }

    return distance;
};


// ---- DOG

Dog_t::Dog_t() : Animal_t("Dog", 11.0) {
    hungry = false;
    starvingTime = 0.0;
}; // TODO(Xavi) 11 meter per sec

void Dog_t::speak() const {
    cout << "Guau Guau!" << flush;
    if(isHungry()){
        cout << ", I am hungry" << flush;   
    }
};

double Dog_t::run(const double dt) {
    starvingTime += dt;
    if(starvingTime > 60. && ! hungry) {
        hungry = true;
    }

    if(hungry) {
        distance += 0.05 * speed * dt;
    }
    else {
        distance += speed * dt;
    }

    return distance;
};

bool Dog_t::isHungry() const {
    return hungry;
}

void Dog_t::eat() {
    starvingTime = 0.0;
    hungry = false;
};


// ---- TURTLE

Turtle_t::Turtle_t() : Animal_t("Turtle", 1.33) {}; // TODO(Xavi) 0.133 meter per sec lest speed it up a bit

double Turtle_t::run(const double dt) {
    distance += speed * dt;
    return distance;
};

void Turtle_t::speak() const {
    cout << "Soc la fabulosa tortuga ninja!" << flush;
};

};// !namespace animals