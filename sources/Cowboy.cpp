#include "Cowboy.hpp"
#include <iostream>
using namespace ariel;
using namespace std;


Cowboy::Cowboy(std::string name, Point spawnLocation) : Character(name, spawnLocation)
{
    hitpoints = 110;
    numberOfBullets = 6;
}

Cowboy::~Cowboy()
{
    
}

void Cowboy::shoot(Character * enemy)
{
    if(enemy == this)
    {
        throw std::runtime_error("No shooting yourself");
    }
    if(!alive)
    {
        throw std::runtime_error("This character is dead (Dead cowboy tried to shoot)");
    }

    if(!enemy->isAlive())
    {
        throw std::runtime_error("Enemy character is dead (Cowboy tried to shoot)");
    }

    if(hasboolets())
    {
        enemy->hit(10);
        numberOfBullets--;
    }
}

bool Cowboy::hasboolets()
{
    if(numberOfBullets)
    {
        return true;
    }

    return false;
}

void Cowboy::reload()
{
    if(!alive)
    {
        throw std::runtime_error("Dead cowboy can't reload");
    }
    numberOfBullets = 6;
}

std::string Cowboy::print()
{
    if (isAlive())
    {
        std::string aliveString = "C, Name: " + name + " Hitpoints: " + std::to_string(hitpoints)
                            + " Location: " + location.print();

        return aliveString;
    }
    else
    {
        std::string deadString = "C, Name: (" + name + ") Hitpoints: --  Location: " + location.print();
        return deadString; 
    }
}
