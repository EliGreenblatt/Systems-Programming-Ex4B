#ifndef OLDNINJA_
#define OLDNINJA_

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
            OldNinja(std::string name, Point spawnLocation);
    };
}


#endif