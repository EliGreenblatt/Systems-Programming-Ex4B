#ifndef TEAM_
#define TEAM_

#include "Point.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>

namespace ariel
{
    class Team
    {
        public:
            Team(Character * otherLeader);
            ~Team();
            void add(Character * newTeamMate);
            Character* closestMember(Character * teamLeader);
            void attack(Team * enemyTeam);
            int stillAlive();
            void print();
            Character * leader;
            std::vector<Character*> team;
            int teamSize;
    };
}

#endif