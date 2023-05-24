#ifndef SMARTTEAM_
#define SMARTTEAM_
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : Team
    {
        public:
            SmartTeam(Character * leader);
            void print();
            void attack(Team * enemyTeam);
    };
}

#endif