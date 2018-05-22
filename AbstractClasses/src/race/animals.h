#ifndef ANIMALS_HEATHER_H
#define ANIMALS_HEATHER_H

#include <iostream>

namespace animals
{
    
class Animal_t  //Abstract class
{
public:
    Animal_t(const std::string & type, double spd = 1.0);
    virtual double run( const double dt ) = 0;//pure virtual function
    virtual void speak() const = 0;//pure virtual function
    void stop();
    void restart();

    virtual void killIt() = 0;
    virtual void eat() = 0;

    //bool operator== (const Animal_t& obj) const;
    bool operator< (const Animal_t& obj) const;

    std::string getType() const;
    double getDistance() const;
    double getSpeed() const;

    friend std::ostream & operator<< (std::ostream& out, const Animal_t& animal);

    virtual bool isTired() const = 0;
    virtual bool isDead() const = 0;
    virtual bool isHungry() const = 0;

protected:

    std::string type;
    double speed; //m/s
    double speed_setting; //m/s
    double distance; //m
};

class Hare_t : public Animal_t //llebre
{
public:
    Hare_t();

    void speak() const;
    double run( const double dt );
    void killIt();
    bool isTired() const;
    bool isDead() const;

    void eat() {};
    bool isHungry() const {};

private:
    bool tired;
    bool dead;

};

class Dog_t : public Animal_t 
{
public:
    Dog_t();

    void speak() const;
    double run( const double dt );
    void eat();

    bool isHungry() const;

    void killIt() {};
    bool isTired() const {};
    bool isDead() const {};

private:
    bool hungry;
    double starvingTime; // in seconds
};

class Turtle_t : public Animal_t 
{
public:
    Turtle_t();

    void speak() const;
    double run( const double dt ); 


    void killIt() {};
    void eat() {};
    bool isTired() const {};
    bool isDead() const {};
    bool isHungry() const {};

};

};//namespace animals

#endif//! ANIMALS_HEATHER_H