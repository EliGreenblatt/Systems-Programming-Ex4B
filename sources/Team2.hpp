#ifndef TEAM2_
#define TEAM2_
#include "Team.hpp"
namespace ariel
{
    class Team2 : public Team
    {
        public:
            Team2(Character * leader);
            void print();
            void attack(Team * enemyTeam);
    };
}

#endif