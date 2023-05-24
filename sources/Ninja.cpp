#include "Ninja.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Ninja::Ninja(std::string name, Point spawnLocation) : Character(name, spawnLocation)
{

}

Ninja::~Ninja()
{
    
}

void Ninja::move(Character * enemy)
{
    location = Point::moveTowards(location, enemy->getLocation() , speed);
}

std::string Ninja::print()
{
    return "";
}

void Ninja::slash(Character * enemy)
{
    if(enemy == this)
    {
        throw std::runtime_error("Can't slash yourself");
    }
    if(!this->isAlive())
    {
        throw std::runtime_error("This character is dead (Ninja Tried To Attack)");
    }
    if(!(enemy->isAlive()))
    {
        throw std::runtime_error("Enemy is dead");
    }
    if(isAlive() && location.distance(enemy->getLocation()) < 1)
    {
        enemy->hit(40);
    }
}