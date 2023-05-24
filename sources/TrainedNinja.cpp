#include "TrainedNinja.hpp"
using namespace ariel;
TrainedNinja::TrainedNinja(std::string name, Point spawnLocation) : Ninja(name, spawnLocation)
{
    speed = 12;
    hitpoints = 120;
}