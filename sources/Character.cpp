#include "Character.hpp"
using namespace std;
using namespace ariel;
#include <iostream>

Character::Character(std::string otherName, Point spawnLocation) : location(spawnLocation)
{
    name = otherName;
    alive = true;
    leader = false;
    isTeam = false;
}

Character::Character()
{

}

Character::~Character()
{
    
}

bool Character::isAlive()
{
    return alive;
}

double Character::distance(Character * otherChar)
{
    return location.distance(otherChar->getLocation());
}

Point Character::getLocation()
{
    return location;
}

std::string Character::getName()
{
    return name;
}

void Character::hit(int damageTaken)
{
    if(damageTaken < 0)
    {
        throw std::invalid_argument("Damage can't be negative");
    }
    if (damageTaken >=hitpoints)
    {
        hitpoints = hitpoints-damageTaken;
        alive = false;
    }
    else if(damageTaken< this->hitpoints)
    {
        hitpoints = hitpoints-damageTaken;
    }

}

void Character::setLeader()
{
    leader = true;
}

bool Character::isLeader()
{
    return leader;
}

void Character::setTeam()
{
    isTeam = true;
}

bool Character::isInTeam()
{
    return isTeam;
}

int Character::getHP()
{
    return hitpoints;
}