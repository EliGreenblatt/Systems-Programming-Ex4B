#include "Team2.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Team2::Team2(Character * leader) : Team(leader)
{
    
}
void Team2::print()
{
    for (std::vector<Cowboy*>::size_type i = 0; i < teamSize; i++)
    {
        team[i]->print();
    }
    
}

void Team2::attack(Team * enemyTeam)
{
        if(enemyTeam == nullptr)
    {
        throw std::invalid_argument("Enemy Team is null");
    }        
    if(leader == nullptr)
    {
        throw std::runtime_error("Leader is null");
    }

    if(!leader->isAlive())
    {
        leader = closestMember(leader);
        if (leader == nullptr)
        {
            return;
        }
    }

    Character * sacrifice = enemyTeam->closestMember(leader);
    if(sacrifice == nullptr)
    {
        return;
    }

    for (std::vector<Cowboy*>::size_type i = 0; i < teamSize; i++)
    {
        if (Cowboy* cowboyPtr = dynamic_cast<Cowboy*>(team[i]))
        {
            if(!cowboyPtr->isAlive())
            {
                continue;
            }
            if (cowboyPtr->hasboolets())
            {
                cowboyPtr->shoot(sacrifice);
            }
            else
            {
                cowboyPtr->reload();
            }
        }
        else  if (Ninja* ninjaPtr = dynamic_cast<Ninja*>(team[i]))
        {
           if(!ninjaPtr->isAlive())
           {
                continue;
           }
           if (ninjaPtr->distance(sacrifice) < 1)
           {
                ninjaPtr->slash(sacrifice);
           }
           else
           {
                ninjaPtr->move(sacrifice);
           }
        }
        if(!sacrifice->isAlive())
        {
            sacrifice = enemyTeam->closestMember(leader);
            if(sacrifice == nullptr)
            {
                printf("Enemy Team Defeated\n");
                return;
            }
        }
    }    
}