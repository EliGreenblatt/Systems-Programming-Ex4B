#include "YoungNinja.hpp"
using namespace ariel;
YoungNinja::YoungNinja(std::string name, Point spawnLocation) : Ninja(name, spawnLocation)
{
    speed = 14;
    hitpoints = 100; 
}