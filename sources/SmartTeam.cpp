#include "SmartTeam.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character * leader) : Team(leader)
{

}

void SmartTeam::print()
{

}

// The smart team will first use the ninjas to attck the closest enemies, because
// the cowboys can shoot from any distance, on top of that both ninjas and cowboys attack the closest enemy to them
// without taking the enemy leader or team leader into consideration, but cowboys will check if they
// can kill anyone this turn.
void SmartTeam::attack(Team * enemyTeam)
{
     if(enemyTeam == nullptr)
    {
        throw std::invalid_argument("Enemy Team is null");
    }       

    if(enemyTeam->stillAlive() <= 0)
    {
        throw std::runtime_error("Enemy Team Has Already Lost");
    }

    if(leader == nullptr)
    {
        throw std::runtime_error("Leader is null");
    }

    if (!leader->isAlive())
    {
        Character* newLeader = closestMember(leader);
        if (newLeader != nullptr)
        {
            leader = newLeader;
        }
        else
        {
            // No living members available, so the team is defeated
            return;
        }
    }  

    Character * sacrifice = enemyTeam->closestMember(team[0]);
    if(sacrifice == nullptr)
    {
        return;
    }

     // now ninjas attack
    for (std::vector<Ninja*>::size_type i = 0; i < teamSize; i++)
    {
        Ninja* ninjaPtr;
        if (Ninja* ninjaPtr = dynamic_cast<Ninja*>(team[i]))
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
            if(i == teamSize -1)
            {
                continue;
            }
            sacrifice = enemyTeam->closestMember(team[i+1]);
            if(sacrifice == nullptr)
            {
                printf("Enemy Team Defeated\n");
                return;
            }
        }

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
        if(!sacrifice->isAlive())
        {
            if(i == teamSize - 1)
            {
                continue;
            }

            int minHealth = 11;
            bool sacrificeSet = false;
            for (std::vector<Character*>::size_type i = 0; i < 10; i++)
            {
                if(enemyTeam->team[i] == nullptr)
                {
                    break;
                }

                if(enemyTeam->team[i]->getHP() > 0 && enemyTeam->team[i]->getHP() < 11)
                {
                    sacrifice = enemyTeam->team[i];
                    sacrificeSet = true;
                }

            }
            
            if(!sacrificeSet)
            {
                sacrifice = enemyTeam->closestMember(team[i+1]);
            }
            
            if(sacrifice == nullptr)
            {
                printf("Enemy Team Defeated\n");
                return;
            }
        }
    }

}