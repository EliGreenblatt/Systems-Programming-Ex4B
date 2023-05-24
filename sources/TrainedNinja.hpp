#ifndef TRAINEDNINJA_
#define TRAINEDNINJA_

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(std::string name, Point spawnLocation);
    };
}


#endif