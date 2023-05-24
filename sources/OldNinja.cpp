#include "OldNinja.hpp"
using namespace ariel;

OldNinja::OldNinja(std::string name, Point spawnLocation) : Ninja(name, spawnLocation)
{
    speed = 8;
    hitpoints = 150;
}
